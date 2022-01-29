add_library(objects STATIC)

target_include_directories(objects
  PUBLIC
    inc
)

target_link_libraries(objects
  PUBLIC
    uart
    flasher
    gpio
  PRIVATE
    system
)

add_subdirectory(src)
