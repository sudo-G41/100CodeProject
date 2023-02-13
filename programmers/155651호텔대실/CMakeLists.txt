cmake_minimum_required(VERSION 3.10)

project(solution VERSION 1.0)

add_subdirectory(solution)

add_executable(main main.c)

target_link_libraries(main solution)
