//
// Created by Michał Wilczyński on 6/7/18.
//

#ifndef TIN_STARTUP_H
#define TIN_STARTUP_H
#include "Broadcast.h"
#include "Server.h"

class Startup {
    Server recvServer;
    Broadcast recvBroadcast;
public:
    void initUDPBroadcastListenerThread();

    void initTCPServerListenerThread();

};


#endif //TIN_STARTUP_H
