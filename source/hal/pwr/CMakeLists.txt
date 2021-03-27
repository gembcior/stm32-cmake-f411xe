add_library(pwr STATIC)

target_include_directories(pwr
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_subdirectory(src)
