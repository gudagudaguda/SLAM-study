cmake_minimum_required(VERSION 3.25)
project(extract33)

set(CMAKE_CXX_STANDARD 17)

include_directories("/usr/local/include/eigen3")
add_executable(extract33 main.cc)
