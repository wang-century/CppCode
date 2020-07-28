cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

# 基础知识练习
project(basic_project)
include_directories(basic_project/include)
add_executable(basic_project
        "basic_project/include/basic_extend.cpp"
        "basic_project/include/basic_extend.h"
        basic_project/main.cpp)

# struct结构体练习项目
project(struct_project)
add_executable(struct_project
        struct_project/project1.h
        struct_project/project1.cpp
        struct_project/project2.h
        struct_project/project2.cpp
        struct_project/main.cpp)

# 类和对象练习项目
project(class_objects_project)

add_executable(class_objects_project
        class_objects_project/main.cpp class_objects_project/head/point.h class_objects_project/point.cpp class_objects_project/Inheritance.cpp class_objects_project/head/Inheritance.h class_objects_project/polymorphism.cpp class_objects_project/head/polymorphism.h)

# 文件操作练习项目
project(file_operation)

add_executable(file_operation
        file_operation/main.cpp)

# C++提高练习项目
project(advance_project)

add_executable(advance_project
        advance_project/main.cpp advance_project/main.cpp advance_project/source/woman.cpp advance_project/header/woman.h advance_project/header/man.hpp advance_project/header/class_template_and_friend.hpp advance_project/header/MyArray.hpp)

# STL练习项目
project(stl_project)

add_executable(stl_project

        stl_project/main.cpp)