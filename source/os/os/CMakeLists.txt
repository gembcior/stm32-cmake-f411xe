add_library(os STATIC)

target_include_directories(os
  PUBLIC
    inc
)

add_subdirectory(src)
