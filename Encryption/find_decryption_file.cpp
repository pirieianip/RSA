/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: find_decryption_file.cpp
 *
 * Description: A reuse function to grab e_n.txt, d_n.txt and p_q.txt.
***********************************************************************************************************************/

#include <fstream>
#include "Encryption.h"

bool Encryption::find_decryption_file(std::string file, Prime &a, Prime &b) {
    std::ifstream pq(file);
    std::string pstring, qstring;
    if(pq.is_open()){
        pq >> pstring >> qstring;
        a = stringToBigUnsigned(pstring);
        b = stringToBigUnsigned(qstring);
        pq.close();
        return true;
    }
    pq.close();
    return false;
}








