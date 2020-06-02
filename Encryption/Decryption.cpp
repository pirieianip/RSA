/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: Decryption.cpp
 *
 * Description: Contains the Decrypt function.
***********************************************************************************************************************/

#include "Encryption.h"
#include <future>
#include <algorithm>

std::string Encryption::Decrypt(std::string Data) {
    Prime d, n;
    BigUnsigned conversion = 0;
    short push = 0;
    char convert = 0;
    std::string mover, ret;
    if(!find_decryption_file("d_n.txt", d, n)){
        throw std::logic_error("d_n.txt not found, Please create or find p_q.txt for decryption.");
    }
    std::vector<std::string> separate_date;
    grab_decryption(separate_date, Data);
    for(auto i: separate_date) {
        BigUnsigned dec = modexp(stringToBigUnsigned(i), d.getValue(), n.getValue());
        while (dec.bitLength() >= 1) {
            conversion = dec & 255;
            push = conversion.toShort();
            convert = static_cast<char>(push);
            mover += convert;
            dec >>= 8;
        }
    }
    std::reverse(mover.begin(),mover.end());
    return std::string(mover.begin(), mover.end()-1);
}
