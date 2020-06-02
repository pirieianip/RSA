cmake_minimum_required(VERSION 3.05)
project(RSA)
set(CMAKE_CXX_STANDARD 17)

add_executable(Test testsuite.cc)

add_library(bigInt435 BigInteger.cc BigInteger.hh BigIntegerAlgorithms.cc BigIntegerAlgorithms.hh BigIntegerLibrary.hh
        BigIntegerUtils.cc BigIntegerUtils.hh BigUnsigned.cc BigUnsigned.hh BigUnsignedInABase.cc BigUnsignedInABase.hh
        NumberlikeArray.hh sha256.cpp sha256.h)

target_link_libraries(Test bigInt435)