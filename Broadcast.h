//
// Created by Michał Wilczyński on 6/7/18.
//

#ifndef TIN_BROADCAST_H
#define TIN_BROADCAST_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

class Broadcast {
    int sockfd;
    struct sockaddr_in their_addr; // connector's address information
    struct hostent *he;
    int numbytes;
    int broadcast = 1;

public:
    void sendDiscoverPacket();

    void listenForDiscoverPackets();

};


#endif //TIN_BROADCAST_H
