cmake_minimum_required(VERSION 3.20)
project(projet_comm)

set(CMAKE_CXX_STANDARD 14)

add_executable(projet_comm main.cpp src/donnee.cpp header/donnee.h src/comm.cpp header/comm.h)
