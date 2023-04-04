cmake_minimum_required(VERSION 3.20)
project(projet_comm)

set(CMAKE_CXX_STANDARD 14)

add_executable(projet_comm main.cpp donnee.cpp donnee.h comm.cpp comm.h)
