cmake_minimum_required(VERSION 3.20)
project(projet_comm)

set(CMAKE_CXX_STANDARD 14)

add_executable(projet_comm sources/main.cpp sources/src/donnee.cpp sources/header/donnee.h sources/src/comm.cpp sources/header/comm.h sources/src/gestion.cpp sources/header/gestion.h sources/header/structureDonnee.h)
