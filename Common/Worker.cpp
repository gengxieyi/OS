#include "Worker.hpp"
#include "OpCtx.hpp"
#include "Connection.hpp"
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include "Common.hpp"
#include "Server.hpp"

int Worker::Start() {
	pthread_t thrd_t;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

	pthread_create(&thrd_t, &attr, _entry_func_, this);
}

void Worker::PostRequest(OpCtx* ctx) {
    mQueue.push(ctx);
}

