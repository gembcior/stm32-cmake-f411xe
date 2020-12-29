cmake_minimum_required(VERSION 3.16)
project(source C CXX ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

set(STM32_CHIP "STM32F411xE")
add_compile_definitions(${STM32_CHIP})

add_subdirectory(main)
add_subdirectory(crt)
add_subdirectory(irq)
add_subdirectory(stm32)
add_subdirectory(hal)
