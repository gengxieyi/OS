#ifndef WORKER_HPP_
#define WORKER_HPP_

#include <queue>
#include "OpCtx.hpp"

class Worker {
    private :
        static void* _entry_func_(void* arg) {
            void* r = ((Worker*)arg)->entry();
            return r;
        }
        void* Entry();
    protected :
        virtual void* entry() = 0;
        std::queue<OpCtx*> mQueue;
    public :
        Worker(){}
        void ProcessResult(OpCtx*) = 0;
        int Start();
        void PostRequest(OpCtx* ctx);
};

#endif
