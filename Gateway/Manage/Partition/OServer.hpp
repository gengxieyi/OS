#ifndef OSERVER_HPP_
#define OSERVER_HPP_

enum ServerStatus {
    SS_online = 1,
    SS_offline,

};

class OServer {
    public :
        OServer(int id,std::string ip) {
            mID = id;
            mIP = ip;
            mStatus = SS_offline;
            mConn = NULL;
        }
        ~OServer() {
        }
        int GetID() {
            return mID;
        }
        std::string GetIP() {
            return mIP;
        }
        void SetConn(Connection* conn) {
            mConn = conn;
        }
        Connection* GetConn() {
            return mConn;
        }
        void SetStatus(int status) {
            mStatus = status;
        }
        int GetStatus() {
            return mStatus;
        }
    private :
        int mID;
        std::string mIP;
        Connection* mConn;
        int mStatus;
};

#endif
