/***********************************************************************************************************************
 * Name: Ian Pirie
 * Date: 02/12/2020
 * File: File_output.cpp
 *
 * Description: Uses the out struct to allow for asychronous file output.
***********************************************************************************************************************/

#include <fstream>
#include "Encryption.h"


void Encryption::file_output(out a) {
    std::ofstream of(a.filename);
    of << bigUnsignedToString(a.a) << "\n" << bigUnsignedToString(a.b);
}