cmake_minimum_required(VERSION 3.10)

project(tutorial3)

add_library(foo SHARED ./foo/foo.cc)

add_executable(main main.cc)

target_link_libraries(main foo)
