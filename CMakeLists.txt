cmake_minimum_required(VERSION 3.31)
project(Task_CLI CXX)

set(CMAKE_CXX_STANDARD 20)
add_executable(Task_CLI main.cpp
        module/task/task.cpp
        module/task/task.h
        module/file/FILE.cpp
        module/file/FILE.h)
