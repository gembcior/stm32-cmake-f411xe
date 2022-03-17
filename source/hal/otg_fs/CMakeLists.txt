add_library(otg_fs STATIC)

target_include_directories(otg_fs
  PUBLIC
    inc
)

add_subdirectory(src)
