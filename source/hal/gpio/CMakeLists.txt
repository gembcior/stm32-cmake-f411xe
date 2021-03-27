add_library(gpio STATIC)

target_include_directories(gpio
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_subdirectory(src)
