cmake_minimum_required(VERSION 3.21)
project(MAMN14 C)

set(CMAKE_C_STANDARD 99)

add_executable(MAMN14 main.c hashmap.c hashmap.h preprocessor.h preprocessor.c assembler_iterations.c assembler_iterations.h file_utils.c file_utils.h assembler_utils.c assembler_utils.h constants.c constants.h errors_utils.c errors_utils.h)
