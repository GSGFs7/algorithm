cmake_minimum_required(VERSION 3.27)

project(1 CXX)

# 更改可执行文件到根目录下
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
# 设置c++版本为20
set(CMAKE_CXX_STANDARD 20)

add_executable(1 1.cpp)

# 用于本地编译的宏
add_compile_definitions(__LOCAL__)
MATH(EXPR stack_size "1000*1024*1024") # 1000MB
# set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}") # 设置栈大小
