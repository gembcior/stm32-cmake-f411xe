add_library(rcc STATIC)

target_include_directories(rcc
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_subdirectory(src)
