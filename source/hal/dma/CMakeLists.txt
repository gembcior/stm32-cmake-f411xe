add_library(dma STATIC)

target_include_directories(dma
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_subdirectory(src)
