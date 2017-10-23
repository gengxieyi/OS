#ifndef COMMON_HPP_
#define COMMON_HPP_
#include <string>
class Request;
class Connection;

int SocketCreate(int port);
Connection* SocketAccept(int st);
int ReadRequest(int st,Request*& req);

void ParseToRequest(char* buf,Request*& req);

#endif
