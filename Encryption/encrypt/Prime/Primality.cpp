/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: Primality.cpp
 *
 * Description: Holds the function which checks for primality.
***********************************************************************************************************************/

#include "Prime.h"

bool Prime::primality(BigUnsigned& value) {
    int size = value.bitLength() / 2;
    BigUnsigned tester = rand();
    for(int i = 0; i < 7; ++i){
        BigUnsigned testvalue = value -1;
        if(modexp(tester, testvalue, value) != 1)
            return false;
        tester += rand();
    }
    return true;
}
