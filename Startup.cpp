//
// Created by Michał Wilczyński on 6/7/18.
//

#include "Startup.h"



void Startup::initUDPBroadcastListenerThread()
{
    std::thread broadcastListenerThread(&Broadcast::listenForDiscoverPackets, recvBroadcast);
}

void Startup::initTCPServerListenerThread()
{
    std::thread serverThread(&Server::startListening, recvServer);
}
