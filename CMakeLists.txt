cmake_minimum_required(VERSION 3.18)
project(Task_CLI CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(module/spdlog)

add_executable(Task_CLI main.cpp
        module/task/task.cpp
        module/task/task.h
        module/file/FILE.cpp
        module/file/FILE.h
        main.cpp)


target_link_libraries(Task_CLI PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)