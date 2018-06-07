/*
** server.c -- a stream socket server demo
*/

#include "Server.h"
#include "Client.h"
#include "Broadcast.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <openssl/sha.h>
#include <openssl/md5.h>

#define PORT "3490"  // the port users will be connecting to

#define BACKLOG 10     // how many pending connections queue will hold


int main(int argc, char* argv[])
{

    unsigned char *blabla;
    Server myServer;
    //myServer.startListening();
    printf("%d\n", SHA256_DIGEST_LENGTH);
    if (argc == 2) {
        Client myClient;
        Broadcast myBroadcast;

        myBroadcast.sendDiscoverPacket();
        char random_data[32];
        //myClient.connectAndSendRequest("127.0.0.1", random_data);
    }
    else {
        Broadcast recvBroadcast;

        recvBroadcast.listenForDiscoverPackets();
        //std::thread serverThread(&Server::startListening, myServer);
        //serverThread.join();
    }

    printf("FINISHED\n");
    return 0;
}