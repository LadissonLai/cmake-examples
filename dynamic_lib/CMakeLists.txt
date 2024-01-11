cmake_minimum_required(VERSION 3.5)
project(dynamic_lib VERSION 1.0)

# complie static library
add_library(mymath_dynamic SHARED ${PROJECT_SOURCE_DIR}/src/mymath.cpp)
target_include_directories(mymath_dynamic PUBLIC ${PROJECT_SOURCE_DIR}/include)

# complie exe
add_executable(main ./src/main.cpp)
target_link_libraries(main PRIVATE mymath_dynamic)


