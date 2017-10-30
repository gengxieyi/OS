#ifndef COMMON_HPP_
#define COMMON_HPP_
#include <string>
class Request;
class Connection;
class OpCtx;

int SocketCreate(int port);
Connection* SocketAccept(int st);
int ReadRequest(int st,Request* req);
void ParseToRequest(char* buf,Request* req);
int SendResponse(int st,OpCtx* req);
void ReadPutRequest(char* buf,Request* req);
void ReadGetRequest(char* buf,Request* req);
void ReadDeleteRequest(char* buf,Request* req);
void ReadAddServerRequest(char* buf,Request* req);
void ReadQueryServerRequest(char* buf,Request* req);
void ReadAddReplicaRequest(char* buf,Request* req);

#endif
