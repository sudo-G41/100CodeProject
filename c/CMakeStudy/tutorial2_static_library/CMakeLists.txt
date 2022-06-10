cmake_minimum_required(VERSION 3.10)

project(tutorial2 VERSION 1.0)

add_library(foo STATIC ./foo/foo.cc)

add_executable(main main.cc)

target_link_libraries(main foo)
