#include "Unit.hpp"

int Unit::Open()
{
    int ret = SUCCESS;
    mFile = fopen(mFileName.c_str(),"a+b");
    if (mFile == NULL) {
        ret = OPEN_FILE_FAILED;
    } else {
        fseek(mFile,0,SEEK_END);
        mOffset = ftell(mFile);
    }
    return ret;
}

int Unit::Close()
{
    return fclose(mFile);
}

int Unit::Write(unsigned char* buf,unsigned int len)
{
    int ret = SUCCESS;
    unsigned int writtens = 0;
    writtens = fwrite(buf,sizeof(char),len,mFile);
    if (writtens != len) {
        ret = WRITE_UNIT_FILE_FAILED;
    } else {
        mOffset += len;
        fflush(mFile);
    }
    return ret;
}

int Unit::Read(unsigned long long offset,
        unsigned char* buf,unsigned int len)
{
    int ret = SUCCESS;
    fseek(mFile,offset,SEEK_SET);
    unsigned int reads = fread(buf,sizeof(char),len,mFile);
    if (reads != len) {
        ret = READ_UNIT_FILE_FAILED;
    }
    return ret;
}
