#ifndef COMMON_HPP_
#define COMMON_HPP_
#include <string>
class Connection;
enum OpType {
    ePut = 1,
    eGet = 2,
    eDelete = 3
};
int SocketCreate(int port);
Connection* SocketAccept(int st);

#endif
