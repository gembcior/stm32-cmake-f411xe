cmake_minimum_required(VERSION 3.20)

include(FetchContent)

FetchContent_Declare(stm32-cmake-utils
  GIT_REPOSITORY https://github.com/gembcior/stm32-cmake-utils.git
  GIT_TAG origin/main
)

FetchContent_GetProperties(stm32-cmake-utils)
FetchContent_MakeAvailable(stm32-cmake-utils)

list(APPEND CMAKE_MODULE_PATH ${stm32-cmake-utils_SOURCE_DIR}/modules)
set(TOOLCHAIN_FILES_PATH ${stm32-cmake-utils_SOURCE_DIR}/toolchains)

project(stm32-cmake-f411re-template)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type." FORCE)
endif()

if (NOT STM32_TOOLCHAIN)
  set(STM32_TOOLCHAIN $ENV{HOME}/tools/toolchains/gcc-arm-none-eabi-10-2020-q4-major CACHE PATH "ARM GCC toolchain." FORCE)
endif()

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/artifacts CACHE PATH "Install path prefix." FORCE)
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

ExternalProject_Add_Step(stm32 openocd
  COMMAND openocd -f ${CMAKE_CURRENT_LIST_DIR}/utils/openocd.cfg
  COMMENT "Running OpenOCD"
  ALWAYS TRUE
  EXCLUDE_FROM_MAIN TRUE
)

ExternalProject_Add_StepTargets(stm32 openocd)

ExternalProject_Add(unittests
  PREFIX            unittests
  SOURCE_DIR        ${CMAKE_CURRENT_SOURCE_DIR}/source
  INSTALL_DIR       ${CMAKE_INSTALL_PREFIX}
  INSTALL_COMMAND   ""
  TEST_COMMAND      ctest
  BUILD_ALWAYS      TRUE
  CMAKE_ARGS        -D CMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
                    -D CMAKE_MODULE_PATH:PATH=${CMAKE_MODULE_PATH}
                    -D CMAKE_TOOLCHAIN_FILE:PATH=${TOOLCHAIN_FILES_PATH}/gcc_unit_tests.cmake
                    -D CMAKE_BUILD_TYPE:STRING="Debug"
                    -D UNIT_TEST:BOOL=ON
)
