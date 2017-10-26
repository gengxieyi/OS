#include "KVDatabase.hpp"
#include <iostream>

int KVDatabase::Open()
{
    int ret = SUCCESS;
    ret = mUnit.Open();
    if (ret) {
        return ret;
    }
    ret = mIndex.Open();
    return ret;
}

int KVDatabase::Close()
{
    int ret = SUCCESS;
    ret = mUnit.Close();
    if (ret) {
        return ret;
    }
    ret = mIndex.Close();
    return ret;
}

int KVDatabase::Write(const string& key,const string& value)
{
    unsigned long long offset = mUnit.GetOffset();
    int ret = mUnit.Write((unsigned char*)value.c_str(),value.length());
    if (ret != 0) {
        std::cout << "write unit failed : " << ret << std::endl;
        return ret;
    }
    ret = mIndex.Put(key,offset,value.length());
    if (ret != 0) {
        std::cout << "write index failed : " << ret << std::endl;
    }
    return ret;
}

string KVDatabase::Read(const string& key)
{
    int ret = SUCCESS;
    unsigned int len = 0;
    unsigned long long offset = 0;
    ret = mIndex.Get(key,offset,len);
    if (ret != 0) {
        std::cout << "read index failed : " << ret << std::endl;
        return "";
    }
    char value[len];
    ret = mUnit.Read(offset,(unsigned char*)value,len);
    if (ret != 0) {
        std::cout << "read unit failed : " << ret << std::endl;
        return "";
    }
    return string(value,len);
}
        
int KVDatabase::List(vector<string>& keys,vector<string>& values)
{
    int ret = SUCCESS;
    vector<unsigned long long> offsets;
    vector<unsigned int> lens;
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
