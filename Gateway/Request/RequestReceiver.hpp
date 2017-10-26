#ifndef NET_SERVER_HPP_
#define NET_SERVER_HPP_
#include "../../Common/Worker.hpp"

class OpCtx;
class RequestReceiver : public Worker {
    public :
        RequestReceiver();
        ~RequestReceiver(){};

    private :
        void* Entry();
        void PostConn(OpCtx*);
        int mFD;
};

#endif

