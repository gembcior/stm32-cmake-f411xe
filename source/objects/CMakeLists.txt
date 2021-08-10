add_library(objects STATIC)

target_include_directories(objects
  PUBLIC
    inc
)

target_link_libraries(objects
  PRIVATE
    system
    uart
    flasher
    irq
)

add_subdirectory(src)
