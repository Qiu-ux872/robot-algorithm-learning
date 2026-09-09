cmake_minimum_required(VERSION 2.8)
project(ransacLineFit)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++14 -O2")

add_executable(ransac_line_fit ransac_line_fit.cpp)
