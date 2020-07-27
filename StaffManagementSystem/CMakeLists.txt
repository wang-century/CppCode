cmake_minimum_required(VERSION 3.16)
project(StaffManagementSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(StaffManagementSystem
        main.cpp
        header/workManager.h
        source/workManager.cpp
        header/worker.h
        header/employee.h
        source/employee.cpp source/manager.cpp header/manager.h source/boss.cpp header/boss.h)