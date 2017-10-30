#ifndef RWHANDLER_HPP_
#define RWHANDLER_HPP_

#include "../../Common/Worker.hpp"

class RWHandler : public Worker {
    public :
        RWHandler(){
            mNextServerId = 0;
            mNextPartitionId = 0;
            mNextReplicaId = 0;
        }
        ~RWHandler(){};
    private :
        void* Entry();
        void ProcessRequest(OpCtx*);
        map<int,OServer*> mServers;
        map<int,Partiotion*> mPartiotions;
        map<int,Replica*> mReplicas;
        int mNextServerId;
        int mNextPartitionId;
        int mNextReplicaId;
}

#endif
