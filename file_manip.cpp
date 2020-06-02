//
// Created by ian on 2/12/20.
//
#include <fstream>
#include "file_manip.h"

std::string readfile(char* file_name){
    std::ifstream input(file_name);
    if(input.is_open()) {
        std::string data;
        input.seekg(0, std::ios::end);
        data.resize(input.tellg());
        input.seekg(0, std::ios::beg);
        input.read(&data[0], data.size());
        input.close();
        return data;
    }
    return NULL;
}

void output_encryption(char* file_name, std::string& enc){
    std::string file(file_name);
    file += ".signed";
    std::ofstream os(file);
    os << enc;
    os.close();
}
