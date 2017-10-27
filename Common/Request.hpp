#ifndef REQUEST_HPP_
#define REQUEST_HPP_
#include <string>

enum OpType {
    ePut = 1,
    eGet,
    eDelete,
};

struct Request {
    int mOpType;
    std::string mKey;
    std::string mValue;
    std::string mIP;
    int mPort;
    std::string mPath;
};

#endif
