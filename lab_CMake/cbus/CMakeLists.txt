cmake_minimum_required(VERSION 3.22)

project(cbus VERSION 0.0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(application)
add_subdirectory(console)
add_subdirectory(generator)
