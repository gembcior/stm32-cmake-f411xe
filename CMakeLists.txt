cmake_minimum_required(VERSION 3.20)

include(FetchContent)

FetchContent_Declare(cmake-utility
  GIT_REPOSITORY  https://github.com/gembcior/cmake-utility.git
  GIT_TAG         origin/main
  GIT_SHALLOW     ON
  GIT_PROGRESS    ON
)

FetchContent_GetProperties(cmake-utility)
FetchContent_MakeAvailable(cmake-utility)

list(APPEND CMAKE_MODULE_PATH ${cmake-utility_SOURCE_DIR}/modules)
set(TOOLCHAIN_FILES_PATH ${cmake-utility_SOURCE_DIR}/toolchains)

project(stm32-cmake-f411re-template)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type." FORCE)
endif()

if (NOT STM32_TOOLCHAIN)
  set(STM32_TOOLCHAIN $ENV{HOME}/tools/toolchains/gcc-arm-none-eabi-10.3-2021.07 CACHE PATH "ARM GCC toolchain." FORCE)
endif()

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/artifacts CACHE PATH "Install path prefix." FORCE)
endif()

include(ExternalProject)

ExternalProject_Add(stm32
  PREFIX            stm32
  SOURCE_DIR        ${CMAKE_CURRENT_SOURCE_DIR}/source
  INSTALL_DIR       ${CMAKE_INSTALL_PREFIX}
  TEST_COMMAND      ""
  BUILD_ALWAYS      TRUE
  CMAKE_ARGS        -D STM32_TOOLCHAIN:PATH=${STM32_TOOLCHAIN}
                    -D CMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
                    -D CMAKE_MODULE_PATH:PATH=${CMAKE_MODULE_PATH}
                    -D CMAKE_TOOLCHAIN_FILE:PATH=${TOOLCHAIN_FILES_PATH}/gcc_stm32f411xe.cmake
                    -D CMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
                    -D UNIT_TEST:BOOL=OFF
)

ExternalProject_Add(unittests
  PREFIX            unittests
  SOURCE_DIR        ${CMAKE_CURRENT_SOURCE_DIR}/source
  INSTALL_DIR       ${CMAKE_INSTALL_PREFIX}
  INSTALL_COMMAND   ""
  TEST_COMMAND      ctest
  BUILD_ALWAYS      TRUE
  CMAKE_ARGS        -D CMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
                    -D CMAKE_MODULE_PATH:PATH=${CMAKE_MODULE_PATH}
                    -D CMAKE_TOOLCHAIN_FILE:PATH=${TOOLCHAIN_FILES_PATH}/gcc_native.cmake
                    -D CMAKE_BUILD_TYPE:STRING="Debug"
                    -D UNIT_TEST:BOOL=ON
)
