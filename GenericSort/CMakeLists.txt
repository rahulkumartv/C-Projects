cmake_minimum_required(VERSION 2.4)
project(GenericSort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Array.h Array.c tArray.c)
add_executable(GenericSort ${SOURCE_FILES})