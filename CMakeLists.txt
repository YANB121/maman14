cmake_minimum_required(VERSION 3.21)
project(MAMN14 C)

set(CMAKE_C_STANDARD 99)

add_executable(MAMN14 main.c utils/hashmap.c utils/hashmap.h preprocessor.h preprocessor.c first_pass.c assembler_iterations.c assembler_iterations.h utils/file_utils.c utils/file_utils.h utils/assembler_utils.c utils/assembler_utils.h utils/constants.c utils/constants.h)
