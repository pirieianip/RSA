/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: Encryption.h
 *
 * Description: Class file for Encryption which inherits RSA
 * Allows contains struct out for asynchronous output to file.
***********************************************************************************************************************/

#ifndef RSA_ENCRYPTION_H
#define RSA_ENCRYPTION_H

#include "encrypt/Encrypt.h"
#include <string>
#include <vector>
#include "../RSA.h"

//Struct to allow for asychronous output to files.
struct out{
    std::string filename;
    BigUnsigned a;
    BigUnsigned b;
};

class Encryption:
        public RSA
{
    // Grabs from string to add to vector, each entry is an addition to the decryption
    static void grab_decryption(std::vector<std::string>& vec, const std::string& data);

    // Makes initial prime for p, q, and e in asynchronous time.
    static void make_pq(int length, Prime& p, Prime& q, Prime& e);

    // Makes n and prints e_n.txt
    static void make_ne(Prime& p, Prime& q, BigUnsigned& n, Prime& e);

    // Makes d and prints d_n.txt
    void make_den(Prime& e, BigUnsigned& n, const BigUnsigned& P, BigUnsigned Q);

    // Outputs encryption to file.
    static void file_output(out a);

    // reused to grab: e_n.txt, d_n.txt, and p_q.txt
    bool find_decryption_file(std::string file, Prime &a, Prime &b);
public:
    // Inherited from RSA Library for reuse.
    std::string Encrypt(std::string Data) override;

    //Inherited from RSA Library for reuse.
    std::string Decrypt(std::string Data) override;

    // Inherited from RSA library for reuse.
    bool Setup(int setup = 512) override;
};


#endif //RSA_ENCRYPTION_H
