# cmake tutorial examples
Three examples.
1. basic cpp compile process.
2. add static or shared library by cmake.
3. using third party library.

本项目提供三个cmake的例子，以供日常使用。
1. 使用cmake编译含有头文件和多个cpp文件的项目，生成可执行文件。
2. 使用cmake编译含生成静态或动态链接库，并引用库文件生成可执行文件。
3. 使用cmake编译调用第三方库的cpp项目，生成可执行文件。

## 第一个项目

使用cmake编译基本的cpp文件，包含多个cpp文件和头文件，没有依赖第三方的库，仅使用了c++标准库。

项目结构如下：

src下两个文件，**main.cpp**调用了**mymath.cpp**文件。

cmakelists.txt文件编写编译规则：

```cmake
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
```

编译方法如下

```shell
mkdir build
cd build
cmake ..
make
# 运行二进制文件
./main
```

## 第二个项目

使用cmake编译生成库文件，并调用库文件生成可执行文件

首先，介绍静态库。静态库区别于动态库，静态库就是在链接（我们把cpp的编译过程分为4个阶段：预处理、编译、汇编、链接，这里的链接指的第四个阶段）时会将目标文件(.o文件)全部打包进二进制文件；动态库就是在链接时不把目标文件打包进二进制文件，而是等到运行时才动态加载。

然后，介绍项目结构。由于在cmake中静态库和动态库的生成命令基本一致，这里仅介绍动态库，静态库看仓库代码即可。我们需要把mymath.cpp编译成动态库，main.cpp调用库函数，生成可执行文件。

cmakelist.txt

```cmake
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
```

## 第三个项目

调用第三方库gtest，然后使用cmake编译。

项目结构：

main.cpp中调用mymath.cpp文件和gtest第三方库，然后使用cmake编译，这里gtest已经提前通过安装好了，安装过程过程自行搜索。

cmakelists.txt

```
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
```

## 完整项目

完整项目请参看github[仓库]()。
