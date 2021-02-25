cmake_minimum_required(VERSION 3.17)
project(Reliability_Network)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Reliability_Network
        README.md
        main.cpp
        main.h Random.cpp Random.h Graph.cpp Graph.h Statistic.cpp Statistic.h MonteCarloMethod.cpp MonteCarloMethod.h DestructionSpectrum.cpp DestructionSpectrum.h Utilities.cpp Utilities.h)
