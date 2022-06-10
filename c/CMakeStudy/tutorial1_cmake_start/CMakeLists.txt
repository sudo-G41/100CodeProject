cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

set(SIDR
		sources
   )

add_executable(Tutorial sources/a.cc ${SIDR}/b.cc)
