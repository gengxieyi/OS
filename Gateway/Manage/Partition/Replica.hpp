#ifndef REPLICA_HPP_
#define REPLICA_HPP_

class Replica {
    public :
        Replica(int id,str::string ip,string path) {
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
