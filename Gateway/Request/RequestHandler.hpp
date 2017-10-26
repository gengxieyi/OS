#ifndef REQUEST_HANDLER_HPP_
#define REQUEST_HANDLER_HPP_

#include "../../Common/Worker.hpp"
#include "../../Worker/DB/KVDatabase.hpp"

class OpCtx;
class Request;
class RequestHandler : public Worker{
    public :
        RequestHandler(): mDB("/home/gxy/","unit","index"){
            mDB.Open();
        };
        ~RequestHandler(){};

    private :
        void ProcessConn(OpCtx* ctx);
        void ProcessRequest(OpCtx* ctx);
        int Read(Request* req);
        int Write(Request* req);
        int Delete(Request* req);
        void* Entry();
        KVDatabase mDB;
};
#endif
