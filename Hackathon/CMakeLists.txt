cmake_minimum_required(VERSION 3.17)
project(Reliability_Hakaton)

set(CMAKE_CXX_STANDARD 17)

add_executable(main ${PROJECT_SOURCE_DIR}/main.cpp Graph.cpp Graph.h Random.cpp Random.h MonteCarlo.cpp MonteCarlo.h main.h Utility.cpp Utility.h)
