cmake_minimum_required(VERSION 3.16)
project(CppCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(struct_project struct_project/main.cpp struct_project/project1.cpp struct_project/project1.h struct_project/project2.cpp struct_project/project2.h)
add_executable(CppCode main.cpp include/swap.cpp include/swap.h struct_project/main.cpp)