cmake_minimum_required(VERSION 3.27)

project(1.cpp)

# 更改到项目根目录下
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main 1.cpp)

# 用于本地编译的宏
add_compile_definitions(__LOCAL__)