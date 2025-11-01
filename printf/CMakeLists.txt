cmake_minimum_required(VERSION 3.30)
project(printf C)

set(CMAKE_C_STANDARD 11)

include_directories(code)

add_executable(printf
    code/extractor.c
    code/ft_printf.c
    code/ft_printf.h
    code/processor.c
    code/utils.c)
