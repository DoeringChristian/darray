cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME darray)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

project(${PROJECT_NAME})
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-g")

file(GLOB SRC_FILES "*.c")
include_directories("./")

add_executable(${PROJECT_NAME} ${SRC_FILES})
