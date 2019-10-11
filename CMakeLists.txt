cmake_minimum_required(VERSION 3.15)
project(idz_1)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

include_directories(
    include
    ${GTEST_INCLUDE_DIRS}
)

add_executable(idz_1 src/main.c src/blank.c src/blank_array.c src/blank_pack.c)
add_executable(Test test/test.cpp src/blank.c src/blank_array.c src/blank_pack.c)

target_link_libraries(Test ${GTEST_LIBRARIES} Threads::Threads)
