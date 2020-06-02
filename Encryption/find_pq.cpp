//
// Created by ian on 1/13/20.
//

#include "Encryption.h"
#include <fstream>

bool Encryption::find_decryption_file(std::string file, Prime &a, Prime &b) {
    std::ifstream pq(file);
    std::string pstring, qstring;
    if(pq.is_open()){
        pq >> pstring >> qstring;
        a = stringToBigUnsigned(pstring);
        b = stringToBigUnsigned(qstring);
        return true;
    }
    return false;
}

