/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: isPrime.cpp
 *
 * Description: A driver program to make sure a big prime number is prime.
***********************************************************************************************************************/

#include "Encryption/encrypt/Prime/bigInt435/BigIntegerLibrary.hh"

int main(){
    BigUnsigned b = stringToBigUnsigned("6703903964971298549787012499102923063739682910296196688861780721860882015036773488400937149083451713845015929093243025426876941405973284973217087192889883");
    BigUnsigned t = 1;
    for(BigUnsigned i = 2; i < b / t; ++i, ++t){
        if(b % i == 0) {
            std::cout << "false";
            return 0;
        }
    }

}