/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: Reprime.cpp
 *
 * Description: Holds the reprime function which allows for a change in prime by increasing or decreasing the bit size.
***********************************************************************************************************************/

#include "Prime.h"

BigUnsigned Prime::reprime(unsigned int length) {
    BigUnsigned value = 1;
    value <<= length - 1;
    while(!primality(value)){
        value += rand();
    }
    return value;
}

void Prime::Reprime(unsigned int length) {
    int l = length;
    value = reprime(l);
}