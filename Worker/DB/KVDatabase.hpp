#ifndef KVDB_HPP_
#define KVDB_HPP_
#include <string>
#include "Index.hpp"
#include "Unit.hpp"

using namespace std;
class KVDatabase {
    public :
        KVDatabase(string dir,string unitname,string indexname) : 
            mUnit(dir + unitname),mIndex(dir + indexname) {
            mDir = dir;
            mUnitName = unitname;
            mIndexName = indexname;
        }
        ~KVDatabase(){};
        gxy_result_t Open();
        gxy_result_t Close();
        gxy_result_t Write(const string& key,const string& value);
        gxy_result_t List(vector<string>&,vector<string>&);
        string Read(const string& key);
    private :
        string mDir;
        string mUnitName;
        string mIndexName;
        Index mIndex;
        Unit mUnit;
};
#endif
