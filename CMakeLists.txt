cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)

project(SICXE-Assembler)

add_executable(
    SICXE-Assembler 
    main.cpp 
    op_table.cpp
    sym_table.cpp
    )