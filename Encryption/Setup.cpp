/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: Setup.cpp
 *
 * Description: Contain the setup function and starts the bad random seeder.
***********************************************************************************************************************/

#include "Encryption.h"

bool Encryption::Setup(int length) {
    srand(time(0));
    Prime p,q,e;
    BigUnsigned n;
    if(!find_decryption_file("p_q.txt", p, q)){
        do {
            make_pq(length, p, q, e);
            make_ne(p, q, n,e);
            make_den(e,n,p.getValue(),q.getValue());
        } while ( euclidean(n,e.getValue()) != 1);
    } else
        return false;
}