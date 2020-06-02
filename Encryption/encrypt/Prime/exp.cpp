/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: exp.cpp
 *
 * Description: Holds the fast exponentiation function and the fast modular exponentiation function.
***********************************************************************************************************************/

#include "Prime.h"
#define one 1

BigUnsigned exp(const BigUnsigned& base,BigUnsigned power){
    BigUnsigned final = 1, start = base, odd;
    bool checker;
    while(power > 0) {
        odd = power & 1;
        checker = odd.toInt();
        switch (checker) {
            case true:
                final *= base;
            case false:
                power >>= 1;
                start *= start;
                break;
        }
    }
    return final;
}

BigUnsigned modexp(BigUnsigned base,BigUnsigned power,BigUnsigned modulus){
    BigUnsigned ret = 1, odd;
    bool checker;

    base %= modulus;

    while(power > 0){
        odd = power & 1;
        checker = odd.toInt();
        switch (checker){
            case true:
                ret = (ret * base) % modulus;
            case false:
                power >>= 1;
                base = (base * base) % modulus;
        }
    }
    return ret;
}


