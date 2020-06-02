/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: Find_n.cpp
 *
 * Description: Makes sure that is lower then delta and that it is relatively prime.
***********************************************************************************************************************/

#include "Encryption.h"

void Encryption::make_ne(Prime &p, Prime &q, BigUnsigned &n, Prime& e) {
    n = p.getValue() * q.getValue();
    BigUnsigned delta = (p.getValue() - 1) * (q.getValue() - 1);
    while((e.getValue() < delta) && euclidean(e.getValue(), delta) != 1){
        unsigned int l = e.getLength() - 1;
        e.Reprime(l);
    }
}
