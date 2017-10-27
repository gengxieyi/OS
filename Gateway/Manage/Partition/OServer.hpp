#ifndef OSERVER_HPP_
#define OSERVER_HPP_

enum ServerStatus {
    SS_online = 1,
    SS_offline,

};

class OServer {
    public :
        OServer() {
        }
        ~OServer() {
        }
    private :
        int mID;
        std::string mIP;
        Connection* mConn;
        int mStatus;
};

#endif
