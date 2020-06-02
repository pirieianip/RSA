/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: RSA.h
 *
 * Description: an interface class for future use.
***********************************************************************************************************************/

#ifndef RSA_RSA_H
#define RSA_RSA_H

#include <string>

class RSA {
protected:
    enum Functionality{
        encrypt,
        decrypt,
    };
public:
    virtual std::string Encrypt(std::string) = 0;
    virtual std::string Decrypt(std::string) = 0;
    virtual bool Setup(int setup) = 0;
};

#endif //RSA_RSA_H
