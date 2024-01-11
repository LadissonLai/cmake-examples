# 总结cmake的基本用法。
cpp编译的基本逻辑：预处理、编译、链接。cmake就是描述了这三个过程，其核心逻辑是找到main函数入口，然后把所有.cpp文件编译成的.o文件链接起来。
那么这里就需要关注：
1. main函数需要链接所有的.o文件，所有.o文件由（cpp和库文件）编译得来，cpp文件又依赖与header文件，库文件同样依赖header文件。
因此写cmake的逻辑就是：exe -> cpp -> headers -> lib -> lib_headers


