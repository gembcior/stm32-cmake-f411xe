add_library(systick STATIC)

target_include_directories(systick
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_subdirectory(src)
