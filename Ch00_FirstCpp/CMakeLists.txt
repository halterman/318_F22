cmake_minimum_required(VERSION 3.11.0)
project(FirstCpp VERSION 0.1.0)

set(CXX_STANDARD 20)
add_compile_options(-Wall -Wextra)
add_executable(FirstCpp main.cpp twice.cpp)
