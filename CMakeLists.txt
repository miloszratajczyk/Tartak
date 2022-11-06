cmake_minimum_required(VERSION 3.23)
project(Tartak)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tartak main.cpp categories.h categories.cpp helpers.h helpers.cpp storage.h storage.cpp product.cpp product.h)
