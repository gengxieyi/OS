#ifndef SERVER_HPP_
#define SERVER_HPP_


#include "Worker.hpp"
#include <map>
#include "CommonDefine.hpp"

class Server {
    private :
        gxy_int32_t mThreadCount;
        gxy_int32_t mIndex;
        std::map<gxy_int32_t,Worker*> mWorkerMap;
    public :
        Server(gxy_int32_t count) {
            mThreadCount = count;
            mIndex = 0;
        }
        gxy_int32_t Init();
        gxy_int32_t Start();
        gxy_int32_t ProcessRequest(OpCtx*);
};

#endif
