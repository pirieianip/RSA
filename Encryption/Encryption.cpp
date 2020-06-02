/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: Encryption.cpp
 *
 * Description: Contains the Encrypt function.
***********************************************************************************************************************/
#include "Encryption.h"
#include <iostream>

std::string Encryption::Encrypt(std::string Data) {
    Prime e, n;
    std::string ret;
    short pusher = 0;
    BigUnsigned mover = 0;
    if(!find_decryption_file("e_n.txt", e, n)){
        throw std::logic_error("e_n.txt not found, Please create or find p_q.txt for decryption.");
    }
    const BigUnsigned E = e.getValue(),
    N = n.getValue();

    for(auto i = Data.begin(); i != Data.end(); ++i) {
        pusher = *i;
        mover += pusher;
        mover <<= 8;
        if (mover > N * 9 / 10) {
            BigUnsigned temp1 = modexp(mover, E, N);
            ret += bigUnsignedToString(temp1) + "\n";
            mover = 0;
        }
    }
    if(mover != 0){
        BigUnsigned temp1 = modexp(mover, E, N);
        ret += bigUnsignedToString(temp1);
    }
    return ret;
}

//Help?


