#ifndef RESPONSE_MANAGER_HPP_
#define RESPONSE_MANAGER_HPP_

#include "../../Common/Server.hpp"

class ResponseManager : public Server {
    public :
        ResponseManager(int count) :Server(count) {
        }
        int Init();
};

#endif
