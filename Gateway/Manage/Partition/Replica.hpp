#ifndef REPLICA_HPP_
#define REPLICA_HPP_

#include <string>

class Replica {
    public :
        Replica(int id,std::string ip,std::string path) {
            mID = id;
            mIP = ip;
            mPath = path;
        }
        ~Replica() {
        }
        int GetID() {
            return mID;
        }
        std::string GetIP() {
            return mIP;
        }
        std::string GetPath() {
            return mPath;
        }
    private :
        int mID;
        std::string mIP;
        std::string mPath;
};

#endif
