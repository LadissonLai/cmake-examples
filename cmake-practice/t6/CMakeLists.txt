cmake_minimum_required(VERSION 3.0)
project(find_cmake_hello)

# 总结：使用find_package的时候，需要提前定义好FindXXX.cmake文件，然后在CMakeLists.txt中使用find_package命令，这样就可以找到对应的库文件了。
# 1. 还需要在FindXXX.cmake文件中定义好各种宏，就像本例中一样。
# 2. FindXXX.cmake文件是区别大小写的。
# 3.如果没有FindXXX.cmake文件，需要定义XXXconfig.cmake文件，或者XXX-config.cmake文件。
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

add_subdirectory(src)

