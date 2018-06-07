//
// Created by Michał Wilczyński on 6/7/18.
//

#include "MerkleDag.h"

//void MerkleNode::addFileInCurrentDirectory(char *data) {

//}

unsigned char* MerkleNode::updateHash() {
    if (children.empty()) {
        calculateHash(value.data, value.data_len, hash);
        return hash;
    }
    else {
        std::vector<unsigned char*> hashes;
        for(auto it : children) {
            hashes.push_back(it->updateHash());
        }


    }
}
