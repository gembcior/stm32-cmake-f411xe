add_library(scb STATIC)

target_include_directories(scb
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_subdirectory(src)
