cmake_minimum_required(VERSION 3.27)

project(1 CXX)

# 设置c++版本为23
set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_CXX_EXTENSIONS OFF) # 禁用GUN扩展
# set(CMAKE_CXX_STANDARD_REQUIRED ON) # 不支持就报错

# 用于本地编译的宏
add_compile_definitions(__LOCAL__)

# 设置栈大小
MATH(EXPR stack_size "1000*1024*1024") # 1000MB
# set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}") # 设置栈大小(Windows)

# 开启O2优化 -Wall启用更多编译器警告
set(CMAKE_CXX_FLAGS "-Wall -O2")

# 调试模式编译
set(CMAKE_BUILD_TYPE Debug)

# 添加可执行文件
add_executable(1 1.cpp)

# 预编译头文件
target_precompile_headers(1 PRIVATE pch.h)

# 生成 compile_commands.json 文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 更改可执行文件到根目录下
set_target_properties(1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)
