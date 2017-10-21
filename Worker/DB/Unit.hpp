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
        gxy_result_t Open();
        gxy_result_t Close();
        gxy_result_t Write(unsigned char* buf,gxy_uint32_t len);
        gxy_result_t Read(gxy_uint64_t offset,unsigned char* buf,gxy_uint32_t len);
        gxy_uint64_t GetOffset() {
            return mOffset;
        }
    private :
        string mFileName;
        FILE* mFile;
        gxy_uint64_t mOffset;
};

#endif
