cmake_minimum_required(VERSION 3.16)

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

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/defaults)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

include(stm32_tools)
include(ExternalProject)

ExternalProject_Add(stm32
  PREFIX            stm32
  SOURCE_DIR        ${CMAKE_CURRENT_SOURCE_DIR}/source
  INSTALL_DIR       ${CMAKE_CURRENT_BINARY_DIR}/artifacts
  TEST_COMMAND      ""
  STEP_TARGETS      configure install
  BUILD_ALWAYS      TRUE
  CMAKE_ARGS        -C ${CMAKE_CURRENT_SOURCE_DIR}/cmake/defaults/stm32_tools.cmake
                    -D CMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
                    -D CMAKE_MODULE_PATH:PATH=${CMAKE_MODULE_PATH}
                    -D CMAKE_TOOLCHAIN_FILE:PATH=${TOOLCHAIN_FILES_PATH}/gcc_stm32f411xe.cmake
                    -D CMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
)

ExternalProject_Get_Property(stm32 INSTALL_DIR)

ExternalProject_Add_Step(stm32 openocd
  COMMAND openocd -f ${CMAKE_CURRENT_LIST_DIR}/utils/openocd.cfg
  COMMENT "Runnin OpenOCD"
  ALWAYS TRUE
  EXCLUDE_FROM_MAIN TRUE
)

ExternalProject_Add_StepTargets(stm32 openocd)
