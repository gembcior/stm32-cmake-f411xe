cmake_minimum_required(VERSION 3.20)
project(source CXX C ASM)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

if (UNIT_TEST)
  include(FetchContent)

  FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
  )

  FetchContent_MakeAvailable(googletest)
endif()

if (NOT UNIT_TEST)
  add_subdirectory(app)
  add_subdirectory(crt)
  add_subdirectory(system)
  add_subdirectory(os)
  add_subdirectory(objects)
endif()

add_subdirectory(dral)
add_subdirectory(hal)
add_subdirectory(lib)
