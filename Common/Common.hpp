#ifndef COMMON_HPP_
#define COMMON_HPP_
#include <string>
enum OpType {
    ePut = 1,
    eGet = 2,
    eDelete = 3
};
int SocketCreate(int port);
int SocketAccept(int st);
std::string GetErrorString(int err);

#endif
