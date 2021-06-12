cmake_minimum_required(VERSION 3.20)
project(source CXX ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

add_subdirectory(app)
add_subdirectory(crt)
add_subdirectory(dral)
add_subdirectory(hal)
add_subdirectory(system)
add_subdirectory(lib)
