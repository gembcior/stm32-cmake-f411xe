add_library(uart STATIC)

target_include_directories(uart
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_subdirectory(src)
