cmake_minimum_required(VERSION 3.05)
project(RSA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 -march=native -pipe -pthread")

add_library(Prime Prime.cpp Prime.h Primality.cpp exp.cpp Reprime.cpp Euclid.cpp)

add_subdirectory(bigInt435)
target_link_libraries(Prime bigInt435)