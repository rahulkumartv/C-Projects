cmake_minimum_required(VERSION 3.4)
project(LinkListGeneral)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES List.h ListTest.c status.h status.c List.c)
add_executable(LinkListGeneral ${SOURCE_FILES})