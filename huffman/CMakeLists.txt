cmake_minimum_required(VERSION 3.6)
project(huffman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp huffman.cpp huffman.h)
add_executable(huffman ${SOURCE_FILES})