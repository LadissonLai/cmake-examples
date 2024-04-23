set(LIBHELLO_SRC hello.cpp)

add_library(hello SHARED ${LIBHELLO_SRC}) # libhello.so

add_library(hello_static STATIC ${LIBHELLO_SRC})
set_target_properties(hello_static PROPERTIES OUTPUT_NAME "hello") # libhello.a

GET_TARGET_PROPERTY(OUTPUT_VALUE hello_static OUTPUT_NAME)
MESSAGE(STATUS "This is the hello_static OUTPUT_NAME: ${OUTPUT_VALUE}")

SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)

# 安装库文件
install(TARGETS hello hello_static
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib    
)
# 安装头文件
install(FILES hello.h 
    DESTINATION include/hello
)






