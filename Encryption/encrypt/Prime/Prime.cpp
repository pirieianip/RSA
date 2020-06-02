/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: Prime.cpp
 *
 * Description: Hold the constructors for the Prime class as well as some operation overloads.
***********************************************************************************************************************/

#include "Prime.h"
#include <cstdio>
#include <ctime>

Prime::Prime() {
}

Prime::Prime(int length): value(1){
    value <<= length - 1;
    std::srand(time(NULL));
    while(!primality(value)){
        value += rand();
    }
}

Prime::Prime(BigUnsigned input) {
    value = input;
}

Prime::Prime(Prime &cut) {
    value = cut.value;
}

std::ostream& operator<<(std::ostream &os, const Prime &prime) {
    os << prime.value;
    return os;
}

bool Prime::operator==(const Prime &rhs) const {
    return value == rhs.value;
}

bool Prime::operator!=(const Prime &rhs) const {
    return !(rhs == *this);
}

BigUnsigned &Prime::operator=(const BigUnsigned &input) {
    value = input;
    primality(value);
    return value;
}




