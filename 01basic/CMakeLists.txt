# 声明camke最低版本
cmake_minimum_required(VERSION 3.5)
# 项目名称以及版本号
project(basic_cmake VERSION 1.0)

# 添加源文件到变量CPP_LIST
aux_source_directory(./src CPP_LIST)
# 生成可执行文件，把可执行文件以来的所有源文件都要添加上
add_executable(main ${CPP_LIST})
# 添加可执行文件的头文件搜索路径
target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)

# debug part
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message("SOURCES: ${CPP_LIST}")
