cmake_minimum_required(VERSION 3.10)

project(DirectoryScope VERSION 1.0)

set(VAR "Hello world")

add_subdirectory(foo)

add_executable(main main.c)

target_link_libraries(main foo)
