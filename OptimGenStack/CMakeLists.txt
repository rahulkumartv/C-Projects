cmake_minimum_required(VERSION 3.4)
project(OptimGenStack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Stack.h Stack.c tStack.c status.h status.c)
add_executable(OptimGenStack ${SOURCE_FILES})