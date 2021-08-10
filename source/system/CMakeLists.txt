add_library(system STATIC)

target_include_directories(system
  PUBLIC
    inc
)

add_subdirectory(src)
