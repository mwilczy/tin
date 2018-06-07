//
// Created by Michał Wilczyński on 6/7/18.
//

#ifndef TIN_BINARYPROTOCOL_H
#define TIN_BINARYPROTOCOL_H



// CODE == 0
// MESSAGE - SAY HELLO
// EVERY OTHER SHOULD CONNECT
// CODE == 1
// MESSAGE - REQUEST HASH
// ONLY HOSTS WITH REQUIRED HASH RESPONDS
struct BroadcastProtocolCodeZero {
    char code;
};

struct BroadcastProtocolCodeOne {
    char code;
    char hash[32];
};



class BinaryProtocol {
};


#endif //TIN_BINARYPROTOCOL_H
