#ifndef NET_SERVER_HPP_
#define NET_SERVER_HPP_
#include "../Common/Server.hpp"
#include "../Common/Connection.hpp"
class ConnWorker : public Worker {
    public :
        ConnWorker(){
        }

    private :
        map<gxy_int32_t,Connection*> mConnMap;
}

#endif

