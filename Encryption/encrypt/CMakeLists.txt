cmake_minimum_required(VERSION 3.05)
project(RSA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 -march=native -pipe -pthread")

add_library(encrypt Encrypt.cpp Encrypt.h Decrypt.cpp Decrypt.h)

add_subdirectory(Prime)
target_link_libraries(encrypt Prime)