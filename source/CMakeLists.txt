cmake_minimum_required(VERSION 3.16)
project(source C CXX ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

include(FetchContent)

FetchContent_Declare(stm32-dral
  GIT_REPOSITORY https://github.com/gembcior/d-ral.git
  GIT_TAG origin/main
)

FetchContent_GetProperties(stm32-dral)
if (NOT stm32-dral_POPULATED)
  FetchContent_Populate(stm32-dral)
  set(DRAL_BRAND stm32)
  set(DRAL_FAMILY f4)
  set(DRAL_CHIP f411xe)
  add_subdirectory(${stm32-dral_SOURCE_DIR} ${stm32-dral_BINARY_DIR})
endif()

add_subdirectory(main)
add_subdirectory(crt)
add_subdirectory(irq)
add_subdirectory(hal)
add_subdirectory(system)
add_subdirectory(objects)
add_subdirectory(flasher)
