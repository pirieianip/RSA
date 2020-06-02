cmake_minimum_required(VERSION 3.05)
project(RSA)
find_package (Threads)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 -march=native -pipe -pthread")


add_library(Encryption Encryption.cpp Encryption.h find_pq.cpp find_decryption_file.cpp Setup.cpp Decryption.cpp make_pq.cpp Find_n.cpp Make_den.cpp File_output.cpp Grab_decryption.cpp)

add_subdirectory(encrypt)

target_link_libraries(Encryption encrypt)
target_link_libraries (Encryption ${CMAKE_THREAD_LIBS_INIT})