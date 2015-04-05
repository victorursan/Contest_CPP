cmake_minimum_required(VERSION 3.1)
project(lab_hw_6_7_Contest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Contest_CPP/Console.cpp
    Contest_CPP/Console.h
    Contest_CPP/Controller.cpp
    Contest_CPP/Controller.h
    Contest_CPP/main.cpp
    Contest_CPP/Participant.cpp
    Contest_CPP/Participant.h
    Contest_CPP/Repository.cpp
    Contest_CPP/Repository.h)

add_executable(lab_hw_6_7_Contest ${SOURCE_FILES})