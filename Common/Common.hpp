#ifndef COMMON_HPP_
#define COMMON_HPP_
#include <string>
class Connection;
enum OpType {
    ePut = 1,
    eGet,
    eDelete,

    ePing = 11,
    
    eAdd = 21,
};

int SocketCreate(int port);
Connection* SocketAccept(int st);
int ReadOp(int st,int* op);

std::string ParseOpCode(int op);

#endif
