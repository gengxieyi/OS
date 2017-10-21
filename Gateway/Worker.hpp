#ifndef WORKER_HPP_
#define WORKER_HPP_

#include <queue>
#include "OpCtx.hpp"

class Worker {
    private :
        std::queue<OpCtx*> mQueue;
        void* entry();
        static void* _entry_func_(void* arg) {
            void* r = ((Worker*)arg)->entry();
            return r;
        }
    public :
        Worker() {};
        int Start();
        void PostRequest(OpCtx* ctx);
        int ProcessRequest(OpCtx* ctx);
        void ProcessPutRequest(OpCtx* ctx);
        void ProcessGetRequest(OpCtx* ctx);
        void ProcessDeleteRequest(OpCtx* ctx);
        int CheckPutPath(const std::string& path);
        int CheckDeletePath(const std::string& path);
};

#endif
