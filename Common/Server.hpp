#ifndef SERVER_HPP_
#define SERVER_HPP_


#include "Worker.hpp"
#include <map>
#include "CommonDefine.hpp"

class Server {
    protected :
        int mThreadCount;
        int mIndex;
        std::map<int,Worker*> mWorkerMap;
    public :
        Server(int count) {
            mThreadCount = count;
            mIndex = 0;
        }
        virtual int Init() = 0;
        int Start();
        int PostRequest(OpCtx*);
};

#endif
