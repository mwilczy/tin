//
// Created by Michał Wilczyński on 6/7/18.
//

#ifndef TIN_CLIENT_H
#define TIN_CLIENT_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define PORT "3490" // the port client will be connecting to

#define MAXDATASIZE 100 // max number of bytes we can get at once

class Client {
    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];
public:
    int connectAndSendRequest(char *ip_addr);
    void* get_in_addr(struct sockaddr *sa);
};


#endif //TIN_CLIENT_H
