#include "RWHandler.hpp"
#include <sstream>

void* Entry()
{
    while (1) {
        if (mQueue.Empty()) {
            usleep(SLEEP_TIME);
        } else {
            OpCtx* ctx = NULL;
            mQueue.Dequeue(ctx);
            if (ctx != NULL) {
                ProcessRequest(ctx);
            }
        }
    }

}

void RWHandler::ProcessRequest (OpCtx* op)
{
    switch (op->GetReq()->mOpType) {
        case eAddServer :
            AddServer(op);
            break;
        case eQueryServer :
            QueryServer(op);
            break;
        case eStartService :
            StartService(op);
            break;
        case eAddReplica :
            AddRplica(op);
            break;
        default :
            op->SetResult(0,"unknown op code");
    }
    WorkerManager::Instance()->GetResponseManager()->PostRequest(op);
}

void RWHandler::AddServer(OpCtx* op)
{
    map<int,OServer*>::iterator iter;
    for (iter = mServers.begin();iter != mServers.end();iter++) {
        if (iter->second->GetIP() == op->GetReq()->mIP) {
            op->SetResult(0,"Server exist");
            return;
        }
    }

    OServer* server = new OServer(++mNextServerId,op->GetReq()->mIP);
    mServers.insert(std::make_pair(server->GetID(),server));
    op->SetResult(0,"Success");
}

void RWHandler::QueryServer(OpCtx* op)
{
    std::stringstream ss;
    ss << mServers.size();
    map<int,OServer*>::iterator iter;
    for (iter = mServers.begin();iter != mServers.end();iter++) {
        ss << iter->second->GetIP();
        ss << iter->second->GetStatus() == SS_online ? "online":"offline";
    }
    op->SetResult(0,ss.str());
}
void RWHandler::StartService(OpCtx* op)
{
    op->SetResult(0,"success");
}
void RWHandler::AddReplica(OpCtx* op)
{
    map<int,OServer*>::iterator iter =  mServers.find(op->GetReq()->mIP);
    map<int,Replica*>::iterator replica_iter;
    if (iter == mServers.end()) {
        op->SetResult(0,"IP not exist");
    }

    for (replica_iter = mReplicas.begin();
            replica_iter != mReplicas.end(); replica_iter++) {
        if (replica_iter->second->GetIP() == op->GetReq()->mIP &&
                replica_iter->second->GetPath() == op->GetReq()->mPath) {
            op->SetResult(0,"replica exist");
        }
    }
    Replica* replica = new Replica(++mNextReplicaId,
            op->GetReq()->mIP,op->GetReq()->mPath);
    mReplicas.insert(std::make_pair(replica->GetID(),replica););
}






