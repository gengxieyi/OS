#ifndef REQUEST_MANAGER_HPP_
#define REQUEST_MANAGER_HPP_


#include "../../Common/Server.hpp"

class RequestManager : public Server {
    public :
        RequestManager(int count) :Server(count) {
        }
        int Init();
};

#endif
