add_library(irq STATIC)

target_include_directories(irq
  PUBLIC
    inc
)

add_subdirectory(src)
