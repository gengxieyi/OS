#include "RWHandler.hpp"
#include <sstream>
#include <unistd.h>
#include "../../Common/CommonDefine.hpp"
#include "../../Common/OpCtx.hpp"
#include "../../Common/Request.hpp"
#include "../Main/WorkerManager.hpp"
#include "Partition/OServer.hpp"
#include "Partition/Partition.hpp"
#include "Partition/Replica.hpp"

void* RWHandler::Entry()
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
            AddReplica(op);
            break;
        default :
            op->SetResult(0,"unknown op code");
    }
    WorkerManager::Instance()->GetResponseManager()->PostRequest(op);
}

void RWHandler::AddServer(OpCtx* op)
{
    std::map<int,OServer*>::iterator iter;
    for (iter = mServers.begin();iter != mServers.end();iter++) {
        if (iter->second->GetIP() == op->GetReq()->mIP) {
            op->SetResult(0,"Server exist");
            return;
        }
    }

    OServer* server = new OServer(++mNextServerId,op->GetReq()->mIP);
    mServers.insert(std::make_pair(server->GetID(),server));
    op->SetResult(0,"success");
}

void RWHandler::QueryServer(OpCtx* op)
{
    std::stringstream ss;
    ss << mServers.size();
    std::map<int,OServer*>::iterator iter;
    std::map<int,Replica*>::iterator replica_iter;
    for (iter = mServers.begin();iter != mServers.end();iter++) {
        ss << iter->second->GetIP();
        ss << (iter->second->GetStatus() == SS_online ? "online":"offline");
        for (replica_iter = mReplicas.begin();
                replica_iter != mReplicas.end();replica_iter++) {
            if (replica_iter->second->GetIP() == iter->second->GetIP()) {
                ss << replica_iter->second->GetPath();
            }
        }
    }
    op->SetResult(0,ss.str());
}
void RWHandler::StartService(OpCtx* op)
{
    op->SetResult(0,"success");
}
void RWHandler::AddReplica(OpCtx* op)
{
    std::map<int,OServer*>::iterator iter ;
    std::map<int,Replica*>::iterator replica_iter;
    for (iter = mServers.begin();iter != mServers.end();iter++) {
        if (iter->second->GetIP() == op->GetReq()->mIP) {
            break;
        }
    }
    if (iter == mServers.end()) {
        op->SetResult(0,"IP not exist");
        return;
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
    mReplicas.insert(std::make_pair(replica->GetID(),replica));
    op->SetResult(0,"success");
}






