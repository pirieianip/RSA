/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: Grab_decryption.cpp
 *
 * Description: Contains the function which separates the various different encryption correctly.
***********************************************************************************************************************/
#include "Encryption.h"

void Encryption::grab_decryption(std::vector<std::string> &vec, const std::string& data) {
    int c = 0;
    std::string temp;
    for(auto i: data){
        switch (i) {
            case '\n':
                if (!temp.empty())
                    vec.push_back(temp);
                temp = "";
                break;
            default:
                temp += i;
                ++c;
                break;
        }
    }
    if(!temp.empty())
        vec.push_back(temp);
}