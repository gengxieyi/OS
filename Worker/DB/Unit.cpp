#include "Unit.hpp"

gxy_result_t Unit::Open()
{
    gxy_result_t ret = SUCCESS;
    mFile = fopen(mFileName.c_str(),"a+b");
    if (mFile == NULL) {
        ret = OPEN_FILE_FAILED;
    } else {
        fseek(mFile,0,SEEK_END);
        mOffset = ftell(mFile);
    }
    return ret;
}

gxy_result_t Unit::Close()
{
    return fclose(mFile);
}

gxy_result_t Unit::Write(unsigned char* buf,gxy_uint32_t len)
{
    gxy_result_t ret = SUCCESS;
    gxy_uint32_t writtens = 0;
    writtens = fwrite(buf,sizeof(char),len,mFile);
    if (writtens != len) {
        ret = WRITE_UNIT_FILE_FAILED;
    } else {
        mOffset += len;
    }
    return ret;
}

gxy_result_t Unit::Read(gxy_uint64_t offset,
        unsigned char* buf,gxy_uint32_t len)
{
    gxy_result_t ret = SUCCESS;
    fseek(mFile,offset,SEEK_SET);
    unsigned int reads = fread(buf,sizeof(char),len,mFile);
    if (reads != len) {
        ret = READ_UNIT_FILE_FAILED;
    }
    return ret;
}
