# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (prl)

find_package(Eigen3 REQUIRED)

include_directories(Eigen)

aux_source_directory(. DIR_SRCS)

add_subdirectory(zcore)
add_subdirectory(zmapping)
# 指定生成目标
add_executable(Demo main.cc)

target_link_libraries(Demo zcore_lib zmapping_lib)

