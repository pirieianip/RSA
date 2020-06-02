//
// Created by ian on 2/12/20.
//

#include "Encryption.h"
#include <future>



void Encryption::make_den(Prime &e, BigUnsigned &n, const BigUnsigned& P, BigUnsigned Q) {
    auto a = std::async(file_output,out{"e_n.txt",e.getValue(),n});
    BigUnsigned inv = modinv(e.getValue(), (P-1)*(Q-1));
    auto b = std::async(file_output,out{"d_n.txt",inv,n});
}