cmake_minimum_required(VERSION 3.25)
project(det33)

set(CMAKE_CXX_STANDARD 17)
include_directories("/usr/local/include/eigen3")
add_executable(det33 main.cc)
