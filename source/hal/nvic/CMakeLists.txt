add_library(nvic STATIC)

target_include_directories(nvic
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_subdirectory(src)
