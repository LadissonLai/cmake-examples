cmake_minimum_required(VERSION 3.5)
project(static_lib VERSION 1.0)

# complie static library
add_library(mymath_static STATIC ${PROJECT_SOURCE_DIR}/src/mymath.cpp)
target_include_directories(mymath_static PUBLIC ${PROJECT_SOURCE_DIR}/include)

# complie exe
add_executable(main ./src/main.cpp)
target_link_libraries(main PRIVATE mymath_static)