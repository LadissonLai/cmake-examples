# include_directories(/usr/local/include/hello)

# find_path(myHeader hello.h)
# if(myHeader)
#     include_directories(${myHeader})
# endif(myHeader)

add_executable(main main.cpp)
# target_link_libraries(main hello) # 链接到动态库
target_link_libraries(main libhello.a) # 链接到动态库

# 总结：make编译时，gcc寻找头文件的默认路径是(/usr/include, /usr/local/include)
# 寻找库文件的默认路径是（/usr/lib, /usr/local/lib）

message(STATUS "in src PROJECT_SOURCE_DIR is : ${PROJECT_SOURCE_DIR}")