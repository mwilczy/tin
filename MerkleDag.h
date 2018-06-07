//
// Created by Michał Wilczyński on 6/7/18.
//

#ifndef TIN_MERKLEDAG_H
#define TIN_MERKLEDAG_H

#include <vector>
#include <string>
#include <openssl/sha.h>
struct Value {
    char type;
    char *name;
    int name_len;
    char *data;
    int data_len;
};

void calculateHash(char *data, int size, unsigned char *hash)
{
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, size);
    SHA256_Final(hash, &sha256);
}


struct MerkleNode {
    Value value;
    std::vector<MerkleNode*> children;
    unsigned char hash[SHA256_DIGEST_LENGTH];

    unsigned char* updateHash();

    //void addFileInCurrentDirectory(char *name, char *data);

   // void addDirectory(char *name);

    //void moveToDirectory(char *name);


};

class MerkleDag {

};


#endif //TIN_MERKLEDAG_H
