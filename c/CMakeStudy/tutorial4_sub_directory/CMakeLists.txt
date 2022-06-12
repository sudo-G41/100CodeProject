cmake_minimum_required(VERSION 3.10)

project(tutorial VERSION 1.0)

add_subdirectory(./foo)

add_executable(main main.cc)

target_link_libraries(main foo)
