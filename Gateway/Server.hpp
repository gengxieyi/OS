#ifndef SERVER_HPP_
#define SERVER_HPP_


#include "Worker.hpp"
#include <map>
#define WORK_BASE "/afei"

class Server {
    private :
        int mThreadCount;
        int mIndex;
        std::map<int,Worker*> mWorkerMap;
    public :
        Server(int count) : mThreadCount(count) {
            mIndex = 0;
        }
        int Start();
        int ProcessRequest(OpCtx*);
};

#endif
