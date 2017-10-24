#ifndef REQUEST_HPP_
#define REQUEST_HPP_

enum OpType {
    ePut = 1,
    eGet,
    eDelete,
}
struct Request {
    int fd
    int mOpType;
    char* mKey;
    int mKeySize;
    char* mValue;
    int mValueSize;
    int mErrCode;
    std::string mErrStr;     
}

#endif
