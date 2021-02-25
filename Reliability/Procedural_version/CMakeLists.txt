cmake_minimum_required(VERSION 3.17)
project(Reliability_Network)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Reliability_Network
        README.md
        Reliability.cpp
        Reliability.h UtilitiesWatch.cpp UtilitiesWatch.h Random.cpp Random.h)
