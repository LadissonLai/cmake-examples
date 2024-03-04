cmake_minimum_required(VERSION 3.5)
project(dynamic_lib VERSION 1.0)

# 添加动态库，不写SHARED默认是动态库
add_library(mymath_dynamic SHARED ${PROJECT_SOURCE_DIR}/src/mymath.cpp)
# 设置动态库的include文件夹
target_include_directories(mymath_dynamic PUBLIC ${PROJECT_SOURCE_DIR}/include)
# 这里的PUBLIC表示对三方的依赖是否传递
# target_link_libraries(main PUBLIC other_lib)

# complie exe
add_executable(main ./src/main.cpp)
# 可执行文件链接动态库
target_link_libraries(main PRIVATE mymath_dynamic)