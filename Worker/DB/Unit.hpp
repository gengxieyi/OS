#ifndef UNIT_HPP_
#define UNIT_HPP_
#include <stdio.h>
#include <string>
#include "../../Common/CommonDefine.hpp"
#include "../../Common/ErrCode.hpp"

using namespace std;
class Unit {
    public :
        Unit(const string& name) {
            mFileName = name;
            mOffset = 0;
        }
        ~Unit(){}
        int Open();
        int Close();
        int Write(unsigned char* buf,unsigned int len);
        int Read(unsigned long long offset,unsigned char* buf,unsigned int len);
        unsigned long long GetOffset() {
            return mOffset;
        }
    private :
        string mFileName;
        FILE* mFile;
        unsigned long long mOffset;
};

#endif
