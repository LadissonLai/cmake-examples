## find_package用法

```cmake
# 在CMAKE_MODULE_PATH下面寻找FindXXX.cmake或者寻找XXXconfig.cmake文件
# 如果找到说明安装了XXX库文件，FindXXX.cmake和XXXconfig.cmake文件内部定义了XXX_INCLUDE_DIR和XXX_LIBS等。一般来说这两个文件会在sudo make install的时候一起安装到系统路径中。
find_package(XXX option)
```
find_package有两种查找模式，
module模式：先在CMAKE_MODULE_PATH查找FindXXX.cmake；然后在/usr/share/cmake-x.y下，找FindXXX.cmake文件。
config模式：如果module没找到，启动config模式。先找XXX_DIR自定义的路径下的XXXConfig.cmake；然后找/usr/lib/cmake或者/usr/local/lib/cmake下面寻找XXXConfig.cmake。

| 优先级 | 搜索模式 | 目标文件 | 搜索路径 |
| :-----| ----: | :----: | :----: |
| P1 | 自定义Module模式 | FindXXX.cmake | CMAKE_MODULE_PATH |
| P2 | 默认Module模式 | FindXXX.cmake | /usr/share/cmake-x.y/Modules |
| P3 | 自定义Config模式 | XXXConfig.cmake | XXX_DIR |
| P4 | 默认Config模式 | XXXConfig.cmake | /usr/lib/cmake/XXX 以及 /usr/local/lib/cmake/XXX |