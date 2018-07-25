cmake_minimum_required(VERSION 3.11)
project(vm2_0_compiler)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCE ${CMAKE_SOURCE_DIR}/source/*.cpp)
file(GLOB HEADER ${CMAKE_SOURCE_DIR}/header/*.h)

add_executable(vm2_0_compiler main.cpp ${SOURCE} ${HEADER})