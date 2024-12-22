cmake_minimum_required(VERSION 3.29)
project(CPP_Project_Tom_Hillman)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CPP_Project_Tom_Hillman
    main.cpp
    people.cpp
    people.h
    readfiles.cpp
    readfiles.h)
