/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: main.cpp
 *
 * Description: Main function of the project, generally controls where things go in the project.
***********************************************************************************************************************/
#include <iostream>
#include "Encryption/Encryption.h"
#include "file_manip.h"
#include <future>
#include <fstream>

int main(int num, char** arg) {
    Encryption encrypt;
    if(num == 1){
        if(encrypt.Setup(512))
            return 0;
        std::cout << "\n\nSetup has already occured.\n\n";
    }
    else if(num == 2){
        std::cout << "\n\nUnknown Command\n\n";
    }
    else if(num == 3){
        if(arg[1][0] == 's'){
            std::string data(readfile(arg[2]));
            std::string hash = sha256(data);
            std::string enc = encrypt.Encrypt(hash);
            output_encryption(arg[2],enc);
            std::ofstream os("signature_file");
            os << hash;
        } else {
            std::cout << "\n\nUnknown Command\n\n";
        }
    }
    else if(num == 4){
        if(arg[1][0] == 'v')
        {
            auto a = std::async(readfile, arg[2]);
            auto b = std::async(readfile, arg[3]);
            std::string sign(a.get());
            std::string orig(b.get());
            std::string orig_hash = sha256(orig);
            std::string dec = encrypt.Decrypt(sign);
            if(dec.compare(orig_hash) == 0)
                std::cout << "\nCorrect hash found.";
            else
                std::cout << "\nIncorrect hash.";
            std::cout << "original hash: \n" << orig_hash << "\n\n"
                << "original hash size: " << orig_hash.size() << "\n"
                << "decrypt hash:\n" << dec << "\n\n"
                << "decrypt hash size: " << dec.size() << "\n\n";
        }
        else
            std::cout << "\n\nUnknown Command\n\n";
    }
}

