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
        int Open();
        int Close();
        int Write(const string& key,const string& value);
        int List(vector<string>&,vector<string>&);
        string Read(const string& key);
    private :
        string mDir;
        string mUnitName;
        string mIndexName;
        Index mIndex;
        Unit mUnit;
};
#endif
