cmake_minimum_required(VERSION 3.16)
project(SpeechContestProcessManagementSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(SpeechContestProcessManagementSystem
        main.cpp sources/speechManager.cpp sources/speechManager.h sources/speaker.h)