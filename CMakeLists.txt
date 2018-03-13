cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 11)
project(SICXE-Assembler)

add_executable(
    SICXE-Assembler 
    main.cpp 
    op_table.cpp
    )