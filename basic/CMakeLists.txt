cmake_minimum_required(VERSION 3.5)
project(basic_cmake VERSION 1.0)

aux_source_directory(./src CPP_LIST)
add_executable(main ${CPP_LIST})
target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)

# debug part
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message("SOURCES: ${CPP_LIST}")
