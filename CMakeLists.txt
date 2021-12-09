cmake_minimum_required(VERSION 3.20)
set(CMAKE_C_STANDARD 99)

set(PROJECT_NAME AdventOfCode2021)
project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} m)
