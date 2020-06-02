/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: make_pq.cpp
 *
 * Description: File for make_pq, sectioned off because of library usage of future and fstream.
***********************************************************************************************************************/

#include "Encryption.h"
#include <future>
#include <fstream>


void Encryption::make_pq(int length, Prime& p, Prime& q, Prime& e) {
    auto a = std::async(Prime::reprime, length);
    auto b = std::async(Prime::reprime, length);
    auto c = std::async(Prime::reprime, length);

    p = a.get();
    q = b.get();
    std::ofstream of("p_q.txt");
    of << bigIntegerToString(p.getValue()) << "\n" << bigUnsignedToString(q.getValue());
    of.close();
    e = c.get();
}






