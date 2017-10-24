#ifndef REQUEST_HANDLER_HPP_
#define REQUEST_HANDLER_HPP_

#include "../Common/Worker.hpp"

class RequestHandler : public Worker{
    public :
        RequestHandler();
        ~RequstHandler(){};

    private :
        void* Entry();
        Locker mLocker;
}
#endif
