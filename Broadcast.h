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

#include <set>
#include <list>
#include <numeric>
#include <chrono>
#include <mutex>
#include <ctime>


#include <stdio.h>
#include <string.h>
class Broadcast {
    int sockfd;
    struct sockaddr_in their_addr; // connector's address information
    struct hostent *he;
    int numbytes;
    int broadcast = 1;
    std::mutex mtx;

    struct addrEntry {
        std::chrono::system_clock::time_point time_;
        sockaddr_in addr_;
        addrEntry(std::chrono::system_clock::time_point time, sockaddr_in addr) : time_(time), addr_(addr) {}
        bool operator==(const addrEntry& lhs)
        {
            if (memcmp(&lhs.addr_,&addr_, sizeof(sockaddr_in)) == 0) {
                return true;
            }
            else {
                return false;
            }
        }
    };

    std::list<addrEntry> neighbors;

    void addNeighbor(sockaddr_in);

public:
    void sendDiscoverPacket();

    void listenForDiscoverPackets();

};


#endif //TIN_BROADCAST_H
