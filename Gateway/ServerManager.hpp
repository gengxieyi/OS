#ifndef SERVERMANAGER_HPP_
#define SERVERMANAGER_HPP_

class ServerManager {
    struct ServerInfo {
        int mID;
        std::string mIP;
        int mPort;
        std::vector<std::string> mDevices;
        int mShardID;
    };
    struct ShardInfo {
        int mID;
        int mServerID;
        std::string mDevice;
    };
}
