add_library(ticktack STATIC)

target_include_directories(ticktack
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_subdirectory(src)
