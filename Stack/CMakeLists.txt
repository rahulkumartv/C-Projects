cmake_minimum_required(VERSION 3.4)
project(Stack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Stack.h Stack.c tStack.c)
add_executable(Stack ${SOURCE_FILES})