#ifndef WORKER_HPP_
#define WORKER_HPP_

#include <queue>
#include "OpCtx.hpp"

class Worker {
    private :
        std::queue<OpCtx*> mQueue;
        static void* _entry_func_(void* arg) {
            void* r = ((Worker*)arg)->entry();
            return r;
        }
    protected :
        virtual void* entry() = 0;
    public :
        Worker() {};
        int Start();
        void PostRequest(OpCtx* ctx);
};

#endif
