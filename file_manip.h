//
// Created by ian on 2/12/20.
//

#ifndef RSA_FILE_MANIP_H
#define RSA_FILE_MANIP_H

#include <string>

// Reads contents into memory real fast.
std::string readfile(char*);

// outputs data to file.
void output_encryption(char* file_name, std::string& enc);

#endif //RSA_FILE_MANIP_H
