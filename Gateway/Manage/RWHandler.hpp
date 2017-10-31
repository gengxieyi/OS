#ifndef RWHANDLER_HPP_
#define RWHANDLER_HPP_

#include <map>
#include "../../Common/Worker.hpp"

class OServer;
class Partition;
class Replica;

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
        void AddServer(OpCtx* op);
        void QueryServer(OpCtx* op);
        void StartService(OpCtx* op);
        void AddReplica(OpCtx* op);
        std::map<int,OServer*> mServers;
        std::map<int,Partition*> mPartiotions;
        std::map<int,Replica*> mReplicas;
        int mNextServerId;
        int mNextPartitionId;
        int mNextReplicaId;
};

#endif
