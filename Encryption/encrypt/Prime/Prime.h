/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: Prime.h
 *
 * Description: A holder class which helps to maintain that a BigUnsigned int is in fact prime.
***********************************************************************************************************************/

#ifndef RSA_PRIME_H
#define RSA_PRIME_H

#include <ostream>
#include "bigInt435/BigIntegerLibrary.hh"
#include "bigInt435/sha256.h"

BigUnsigned exp(const BigUnsigned& base,BigUnsigned power);
BigUnsigned modexp(BigUnsigned base,BigUnsigned power,BigUnsigned modulus);
BigUnsigned euclidean(BigUnsigned a, BigUnsigned b);
BigUnsigned euclidean_helper(BigUnsigned& a, BigUnsigned& b);
BigUnsigned lcm(BigUnsigned& a, BigUnsigned& b);

class Prime {
    BigUnsigned value;

    static bool primality(BigUnsigned& value);
public:
    Prime();
    explicit Prime(int length);
    explicit Prime(BigUnsigned input);
    Prime(Prime& cut);

    BigUnsigned getValue(){return value;};
    int getLength(){return value.getLength();};

    static BigUnsigned reprime(unsigned int length);
    void Reprime(unsigned int length);

    friend std::ostream &operator<<(std::ostream &os, const Prime &prime);
    BigUnsigned& operator=(const BigUnsigned& input);

    bool operator==(const Prime &rhs) const;

    bool operator!=(const Prime &rhs) const;
};


#endif //RSA_PRIME_H


