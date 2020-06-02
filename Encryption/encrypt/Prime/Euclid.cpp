/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: Euclid.cpp
 *
 * Description: Holds the Extended Euclid algorithm.
***********************************************************************************************************************/
#include "Prime.h"

BigUnsigned euclidean(BigUnsigned a, BigUnsigned b){
    if(a < b)
        return euclidean_helper(b, a);
    else if(a > b)
        return euclidean_helper(a, b);
    else
        return a;
}


BigUnsigned euclidean_helper(BigUnsigned& a, BigUnsigned& b){
    if(b == 0)
        return a;
    BigUnsigned c = a % b;
    return(euclidean_helper(b, c));
}