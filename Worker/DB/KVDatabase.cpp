#include "KVDatabase.hpp"

gxy_result_t KVDatabase::Open()
{
    gxy_result_t ret = SUCCESS;
    ret = mUnit.Open();
    if (ret) {
        return ret;
    }
    ret = mIndex.Open();
    return ret;
}

gxy_result_t KVDatabase::Close()
{
    gxy_result_t ret = SUCCESS;
    ret = mUnit.Close();
    if (ret) {
        return ret;
    }
    ret = mIndex.Close();
    return ret;
}

gxy_result_t KVDatabase::Write(const string& key,const string& value)
{
    gxy_uint64_t offset = mUnit.GetOffset();
    gxy_result_t ret = mUnit.Write((unsigned char*)value.c_str(),value.length());
    if (ret != 0) {
        return ret;
    }
    ret = mIndex.Put(key,offset,value.length());
    return ret;
}

string KVDatabase::Read(const string& key)
{
    gxy_result_t ret = SUCCESS;
    gxy_uint32_t len = 0;
    gxy_uint64_t offset = 0;
    ret = mIndex.Get(key,offset,len);
    if (ret != 0) {
        return "";
    }
    char value[len];
    ret = mUnit.Read(offset,(unsigned char*)value,len);
    if (ret != 0) {
        return "";
    }
    return string(value,len);
}
        
gxy_result_t KVDatabase::List(vector<string>& keys,vector<string>& values)
{
    gxy_result_t ret = SUCCESS;
    vector<gxy_uint64_t> offsets;
    vector<gxy_uint32_t> lens;
    mIndex.List(keys,offsets,lens);
    if (keys.size() != offsets.size() || keys.size() != lens.size()) {
        ret = LIST_INDEX_ERROR;
    }
    for (int i = 0 ; i < keys.size();i++) {
        char value[lens[i]];
        ret = mUnit.Read(offsets[i],(unsigned char*)value,lens[i]);
        if (ret != SUCCESS) {
            return ret;
        }
        values.push_back(string(value,lens[i]));
    }
}
