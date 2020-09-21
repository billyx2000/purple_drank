cmake_minimum_required(VERSION 3.10)
project(networld LANGUAGES C)

# Activate C99 standard:
SET(CMAKE_C_FLAGS "-g -std=c99 -Wall -Wextra" )

# RayLib:
find_package(raylib 2.0 REQUIRED)
#set(raylib_VERBOSE 1)

# project configuration :
include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)

add_executable(nw-hello src/hello.c)
target_link_libraries(nw-hello raylib)

add_executable(nw-viewer src/main-viewer.c src/networld.c)
target_link_libraries(nw-viewer raylib)