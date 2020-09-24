project(networld LANGUAGES C)
cmake_minimum_required(VERSION 3.10)

# Activate C99 standard:
SET(CMAKE_C_FLAGS "-std=c99 -Wall -Wextra" )

# project configuration :
include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)

# RayLib:
find_package(raylib 3.0 REQUIRED)
#set(raylib_VERBOSE 1)

add_executable(nw-hello src/hello.c)
target_link_libraries(nw-hello raylib)

add_executable(nw-viewer src/main-viewer.c src/networld.c)
target_link_libraries(nw-viewer raylib)

#without cmake package... 
#include_directories(${PROJECT_SOURCE_DIR}/raylib/src)
#link_directories(${PROJECT_SOURCE_DIR}/raylib)
#target_link_libraries(nw-viewer raylib GL m pthread dl rt X11)
