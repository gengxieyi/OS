#include "Worker.hpp"
#include <pthread.h>
#include <vector>

int Worker::Start() {
	pthread_t thrd_t;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

	pthread_create(&thrd_t, &attr, _entry_func_, this);

    return 0;
}

void Worker::PostRequest(OpCtx* ctx) {
    mQueue.Enqueue(ctx);
}

