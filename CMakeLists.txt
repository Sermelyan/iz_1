cmake_minimum_required(VERSION 3.15)
project(idz_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(idz_1 src/main.c src/blank.c src/blank_array.c src/blank_pack.c)