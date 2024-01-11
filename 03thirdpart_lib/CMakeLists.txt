cmake_minimum_required(VERSION 3.5)
project(std_cmake_project VERSION 1.0)

find_package(GTest REQUIRED)
message("GTEST_LIBRARIES: ${GTEST_LIBRARIES}")
message("GTEST_INCLUDE_DIRS: ${GTEST_INCLUDE_DIRS}")


# Include directories for GTest and project source files
include_directories(${GTEST_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)

add_executable(main ./src/main.cpp)
target_link_libraries(main ${GTEST_LIBRARIES} /usr/local/lib/libmymath_dynamic.so)
