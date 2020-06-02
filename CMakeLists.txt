cmake_minimum_required(VERSION 3.05)
project(RSA)

set(CMAKE_CXX_STANDARD 17)

add_executable(rsa435.exe main.cpp Encryption/encrypt/Prime/bigInt435 Encryption RSA.h file_manip.h file_manip.cpp)

add_executable(sign.exe main.cpp Encryption/encrypt/Prime/bigInt435 Encryption RSA.h file_manip.h file_manip.cpp)

add_executable(isPrime isPrime.cpp Encryption)

add_subdirectory(Encryption)
target_link_libraries(rsa435.exe Encryption)
target_link_libraries(sign.exe Encryption)
target_link_libraries(isPrime Encryption)
