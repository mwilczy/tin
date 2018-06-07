/*
** server.c -- a stream socket server demo
*/

#include "Server.h"
#include "Client.h"

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


#define PORT "3490"  // the port users will be connecting to

#define BACKLOG 10     // how many pending connections queue will hold



int main(int argc, char* argv[])
{
    Server myServer;
    //myServer.startListening();
    printf("%d\n", SHA256_DIGEST_LENGTH);
    if (argc == 2) {
        Client myClient;
        myClient.connectAndSendRequest("127.0.0.1");
    }
    else {
        std::thread serverThread(&Server::startListening, myServer);
        serverThread.join();
    }

    printf("FINISHED\n");
    return 0;
}