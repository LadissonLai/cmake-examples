cmake_minimum_required(VERSION 3.5)
project(std_cmake_project VERSION 1.0)

find_package(GTest REQUIRED)
message("GTEST_LIBRARIES: ${GTEST_LIBRARIES}")
message("GTEST_INCLUDE_DIRS: ${GTEST_INCLUDE_DIRS}")

# 添加动态库
add_library(mymath_dynamic SHARED ${PROJECT_SOURCE_DIR}/src/mymath.cpp)
# 设置动态库的include文件夹
target_include_directories(mymath_dynamic PUBLIC ${PROJECT_SOURCE_DIR}/include)

# 添加测试可执行文件
add_executable(main ./src/main.cpp)
# 添加可执行文件的依赖库和依赖头文件
target_include_directories(main PUBLIC ${GTEST_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(main ${GTEST_LIBRARIES} mymath_dynamic pthread) # 注意要链接pthread库，是个bug
