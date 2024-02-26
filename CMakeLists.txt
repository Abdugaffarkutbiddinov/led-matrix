cmake_minimum_required(VERSION 3.26)
project(led_matrix)

set(CMAKE_CXX_STANDARD 11)

add_executable(led_matrix main.cpp
        MatrixDisplay.hpp
        MatrixDisplay.cc)
