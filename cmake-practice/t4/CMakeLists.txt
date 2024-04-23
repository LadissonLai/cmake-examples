cmake_minimum_required(VERSION 2.8)
project(hello)

add_subdirectory(src)

message(STATUS "outer PROJECT_SOURCE_DIR is : ${PROJECT_SOURCE_DIR}")
message(STATUS "!!!CMAKE_MODULE_PATH is : ${CMAKE_MODULE_PATH}!!")