cmake_minimum_required(VERSION 3.21)
project(MAMN14 C)

set(CMAKE_C_STANDARD 99)

add_executable(MAMN14 main.c hashmap.c hashmap.h preprocessor.h preprocessor.c first_pass.c)
