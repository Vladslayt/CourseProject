cmake_minimum_required(VERSION 3.22)
project(Kursach_DA)

set(CMAKE_CXX_STANDARD 14)

add_executable(Kursach_DA main.cpp "AbstractFactory.h" AbstractStorage.h PopulationCensus.h menu.h SingleListLink.h)
