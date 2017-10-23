#include "Connection.hpp"
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Common.hpp"

Connection::~Connection() {
    close(mClientSocket);
}

