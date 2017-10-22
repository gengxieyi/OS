#include "OpCtx.hpp"

void OpCtx::SetType(int type) {
    mOpType = type;
}

int OpCtx::GetType() {
    return mOpType;
}

Connection* OpCtx::GetConn() {
    return mConn;
}
