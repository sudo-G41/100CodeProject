add_library(foo STATIC foo.c)

target_compile_definitions(foo PUBLIC VAR="${VAR}")
