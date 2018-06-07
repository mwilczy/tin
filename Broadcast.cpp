//
// Created by Michał Wilczyński on 6/7/18.
//

#include "Broadcast.h"

#define SERVERPORT 4950    // the port users will be connecting to

void Broadcast::sendDiscoverPacket()
{
    if ((he=gethostbyname("255.255.255.255")) == NULL) {  // get the host info
        perror("gethostbyname");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // this call is what allows broadcast packets to be sent:
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast,
                   sizeof broadcast) == -1) {
        perror("setsockopt (SO_BROADCAST)");
        exit(1);
    }

    their_addr.sin_family = AF_INET;     // host byte order
    their_addr.sin_port = htons(SERVERPORT); // short, network byte order
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(their_addr.sin_zero, '\0', sizeof their_addr.sin_zero);

    if ((numbytes=sendto(sockfd, "RANDOM MESSAGE", strlen("RANDOM MESSAGE"), 0,
                         (struct sockaddr *)&their_addr, sizeof their_addr)) == -1) {
        perror("sendto");
        exit(1);
    }

    printf("sent %d bytes to %s\n", numbytes,
           inet_ntoa(their_addr.sin_addr));

    close(sockfd);
}

void Broadcast::listenForDiscoverPackets()
{
    sockaddr_in si_me, si_other;
    int s;
    s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    int port=SERVERPORT;
    int broadcast=1;

    setsockopt(s, SOL_SOCKET, SO_BROADCAST,
               &broadcast, sizeof broadcast);

    memset(&si_me, 0, sizeof(si_me));
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(port);
    si_me.sin_addr.s_addr = INADDR_ANY;

    bind(s, (sockaddr *)&si_me, sizeof(sockaddr));

    while(1)
    {
        char buf[10000];
        unsigned slen=sizeof(sockaddr);
        recvfrom(s, buf, sizeof(buf)-1, 0, (sockaddr *)&si_other, &slen);

        printf("recv: %s\n", buf);
    }
}