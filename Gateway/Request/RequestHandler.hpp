#ifndef REQUEST_HANDLER_HPP_
#define REQUEST_HANDLER_HPP_

#include "../../Common/Worker.hpp"

class OpCtx;
class Request;
class RequestHandler : public Worker{
    public :
        RequestHandler() {
        };
        ~RequestHandler(){};

    private :
        void ProcessConn(OpCtx* ctx);
        void* Entry();
};
#endif
