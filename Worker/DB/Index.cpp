#include "Index.hpp"

void Index::Release(Node* n)
{
    if (n != NULL) {
        Release(n->mLeft);
        Release(n->mRight);
        delete n;
    }
}

gxy_result_t Index::Put(const string& key,gxy_uint64_t offset,gxy_uint32_t len)
{
    if (Find(key)) {
        return INDEX_ALREADY_EXIST;
    }
    Node* node = new Node(key,offset,len);
    node->mIndex = mBitset.FindFirst();

    if (node->mIndex >= mBitset.GetSize()) {
        delete node;
        return INDEX_FULL;
    }

    int ret = Flush(node);
    if (ret) {
        delete node;
        return ret;
    }
    return Insert(mHeader,node);
}

gxy_result_t Index::Insert(Node*& p,Node* n)
{
    int ret = SUCCESS;
    if (p == NULL) {
        p = n;
        mBitset.Set(n->mIndex);
    } else if (n->mKey > p->mKey) {
        Insert(p->mRight,n);
    } else if (n->mKey < p->mKey) {
        Insert(p->mLeft,n);
    } else {
        ret = INDEX_ALREADY_EXIST;
    }
    return ret;
}
        
bool Index::Find(const string& key)
{
    bool result = false;
    Node* p = mHeader;
    while(p != NULL) {
        if (p->mKey == key) {
            result = true;
            break;
        } else if (p->mKey > key) {
            p = p->mLeft;
        } else {
            p = p->mRight;
        }
    }
    return result;
}

gxy_result_t Index::Get(const string& key,gxy_uint64_t& offset,
        gxy_uint32_t& len)
{
    Node* p = mHeader;
    while(p != NULL) {
        if (p->mKey == key) {
            len = p->mValueSize;
            offset = p->mOffset;
            return SUCCESS;
        } else if (p->mKey > key) {
            p = p->mLeft;
        } else {
            p = p->mRight;
        }
    }
    return INDEX_NOT_EXIST;
}

gxy_result_t Index::Open()
{
    int ret = SUCCESS;
    if (access(mFileName.c_str(),F_OK) < 0) {
        mFile = fopen(mFileName.c_str(),"w+b");
    } else {
        mFile = fopen(mFileName.c_str(),"r+");
    }

    if (mFile == NULL) {
        ret = OPEN_FILE_FAILED;
    } else {
        fseek(mFile,0,SEEK_END);
        gxy_int64_t len = ftell(mFile);
        if(0 == len) {
            FlushBitset();
        } else if (INDEX_COUNT / 8 <= len) {
            ret = ReloadBitset();
            if (!ret) {
                ret = ReloadIndex();
            }
        } else {
            ret = FILE_DATA_BROKEN;
        }
        
    }
    return ret;
}

gxy_result_t Index::FlushBitset() {
    fseek(mFile,0,SEEK_SET);
    int len = fwrite(mBitset.GetChar(0),sizeof(char),INDEX_COUNT / 8,mFile);
    if (len == INDEX_COUNT / 8) {
        return SUCCESS;
    } else {
        return WRITE_INDEX_FILE_FAILED;
    }
}

gxy_result_t Index::ReloadBitset() {
    fseek(mFile,0,SEEK_SET);
    int len = fread(mBitset.GetChar(0),sizeof(char),INDEX_COUNT / 8,mFile);
    if (len == INDEX_COUNT / 8) {
        return SUCCESS;
    } else {
        return READ_INDEX_FILE_FAILED;
    }

}

gxy_result_t Index::ReloadIndex() {
    int ret = SUCCESS;
    for (int i = 0;i < mBitset.GetSize();i++) {
        if (mBitset.Test(i)) {
            Node* node = new Node();
            node->mIndex = i;
            ret = Decode(node);
            if (ret) {
                delete node;
                break;
            }
            Insert(mHeader,node);
        }
    }
    return ret;
}

gxy_result_t Index::Close()
{
    return fclose(mFile);
}

gxy_result_t Index::Flush(Node* n)
{
    int ret = SUCCESS;
    gxy_uint32_t index = n->mIndex;
    int offset = INDEX_COUNT / 8 + index * 52;
    fseek(mFile,offset,SEEK_SET);
    int len = fwrite(&n->mOffset,sizeof(gxy_uint64_t),1,mFile);
    if (len != 1) {
        return WRITE_INDEX_FILE_FAILED;
    }

    len = fwrite(&n->mValueSize,sizeof(gxy_uint32_t),1,mFile);
    if (len != 1) {
        return WRITE_INDEX_FILE_FAILED;
    }

    len = fwrite(&n->mIndex,sizeof(gxy_uint32_t),1,mFile);
    if (len != 1) {
        return WRITE_INDEX_FILE_FAILED;
    }

    gxy_uint32_t length = n->mKey.length();
    len = fwrite(&length,sizeof(gxy_uint32_t),1,mFile);
    if (len != 1) {
        return WRITE_INDEX_FILE_FAILED;
    }

    len = fwrite(n->mKey.c_str(),sizeof(char),length,mFile);
    if (len != length) {
        return WRITE_INDEX_FILE_FAILED;
    }

    fseek(mFile,index / 8,SEEK_SET);
    mBitset.Set(index);
    len = fwrite(mBitset.GetChar(index / 8),sizeof(char),1,mFile);
    if (len != 1) {
        return WRITE_INDEX_FILE_FAILED;
    }

    mBitset.Reset(index);
    return ret;
}

gxy_result_t Index::Decode(Node* n)
{
    int ret = SUCCESS;
    gxy_uint32_t index = n->mIndex;
    int offset = INDEX_COUNT / 8 + index * 52;
    fseek(mFile,offset,SEEK_SET);
    int len = fread(&n->mOffset,sizeof(gxy_uint64_t),1,mFile);
    if (len != 1) {
        return READ_INDEX_FILE_FAILED;
    }

    len = fread(&n->mValueSize,sizeof(gxy_uint32_t),1,mFile);
    if (len != 1) {
        return READ_INDEX_FILE_FAILED;
    }

    len = fread(&n->mIndex,sizeof(gxy_uint32_t),1,mFile);
    if (len != 1) {
        return READ_INDEX_FILE_FAILED;
    }

    gxy_uint32_t length = 0;
    len = fread(&length,sizeof(gxy_uint32_t),1,mFile);
    if (len != 1) {
        return READ_INDEX_FILE_FAILED;
    }

    char ch[length];
    len = fread(ch,sizeof(char),length,mFile);
    if (len != length) {
        return READ_INDEX_FILE_FAILED;
    }

    n->mKey = string(ch,length);
    return ret;
}
        
void Index::List(vector<string>& keys,
        vector<gxy_uint64_t>& offsets,vector<gxy_uint32_t>& lens)
{
    List(mHeader,keys,offsets,lens);
}

void Index::List(Node* p,vector<string>& keys,
        vector<gxy_uint64_t>& offsets,vector<gxy_uint32_t>& lens)
{
    if (p == NULL) {
        return;
    }
    List(p->mLeft,keys,offsets,lens);
    keys.push_back(p->mKey);
    offsets.push_back(p->mOffset);
    lens.push_back(p->mValueSize);
    List(p->mRight,keys,offsets,lens);
}
