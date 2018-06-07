//
// Created by john on 6/7/18.
//

#ifndef TIN_INTERFACE_H
#define TIN_INTERFACE_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <cstring>
#include <string>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>


class CliInterface {
public:
    void startInterface();
    int discover(); //shows other hosts
    std::string ls(std::string hash); // shows files in the filesystem based on given hash
    int lsh(); // shows all hashes
    void create(); // starts interactive communication with the user
    void cd(std::string path); //open a folder based on given path in create mode
    std::string mkdir(std::string name); //makes new folder in create mode
    void touch(std::string name); //makes new text file in create mode
    void publish(); //publishes changes in create mode
    void search(std::string hash); //starts broadcast in order to find  given hash in ipfs
    void download(std::string hash); // starts downloading based on given hash




};


#endif //TIN_INTERFACE_H
