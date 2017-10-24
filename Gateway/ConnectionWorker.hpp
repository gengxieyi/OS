#ifndef NET_SERVER_HPP_
#define NET_SERVER_HPP_
#include "../Common/Worker.hpp"
#include "../Common/CommonDefine.hpp"
#include "../Common/Locker.hpp"
#include <map>

class OpCtx;
class Connection;

class ConnWorker : public Worker {
    public :
        ConnWorker();
        ~ConnWorker(){};
        void SetFree(gxy_int32_t);

    private :
        void* Entry();
        Locker mLocker;
        std::map<gxy_int32_t,Connection*> mConnMap;
        gxy_int32_t mFD;
};

#endif

