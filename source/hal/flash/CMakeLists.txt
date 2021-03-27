add_library(flash STATIC)

target_include_directories(flash
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_subdirectory(src)
