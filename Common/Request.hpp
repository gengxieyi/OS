#ifndef REQUEST_HPP_
#define REQUEST_HPP_
#include <string>

enum OpType {
    ePut = 1,
    eGet,
    eDelete,
};
struct Request {
    int mFD;
    int mOpType;
    std::string mKey;
    std::string mValue;
    int mErrCode;
    std::string mErrStr;     
};

#endif
