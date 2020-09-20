cmake_minimum_required(VERSION 3.10)
project(networld LANGUAGES C)

# Activate C99 standard:
SET(CMAKE_C_FLAGS "-std=c99 -Wall -Wextra" )

# RayLib:
find_package(raylib 2.0 REQUIRED)

# project configuration :
include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)

add_executable(nw-test src/test.c)
#set(raylib_VERBOSE 1)
target_link_libraries(nw-test raylib)
