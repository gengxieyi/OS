#ifndef REQUEST_HPP_
#define REQUEST_HPP_
#include <string>

enum OpType {
    ePut = 1,
    eGet,
    eDelete,

    eAddServer = 10,
    eQueryServer,
    eStartService,
    eAddReplica,
};

struct Request {
    int mOpType;
    std::string mKey;
    std::string mValue;
    std::string mIP;
    std::string mPath;
    int mPartitionNum;
};

#endif
