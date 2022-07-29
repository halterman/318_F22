cmake_minimum_required(VERSION 3.11)
project(test2)

# C++20
set(CMAKE_CXX_STANDARD 20)

# Adjust the warning level to high
add_compile_options(-Wall -Wextra)

add_executable(test2 test2.cpp)
