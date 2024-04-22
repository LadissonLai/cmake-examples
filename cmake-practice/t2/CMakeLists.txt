cmake_minimum_required(VERSION 2.8)
PROJECT(HELLO)

MESSAGE(STATUS "This is BINARY dir " ${HELLO_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${HELLO_SOURCE_DIR})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) #设置可执行文件的输出路径
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) # 设置lib输出路径

add_subdirectory(src bin) # ADD_SUBDIRECTORY(source_dir [binary_dir] [EXCLUDE_FROM_ALL]) 用于向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制存放的位置
# add_subdirectory(src)

set(CMAKE_INSTALL_PREFIX "/home/u18/cmake_install") # 可以在外部设置安装路径

install(FILES COPYRIGHT README
    DESTINATION share/doc/
)

install(PROGRAMS runhello.sh
        DESTINATION bin
    )

install(DIRECTORY doc 
        DESTINATION share/doc
    )