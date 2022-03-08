target_sources(tinyusb
  PRIVATE
    port.cpp
    usb_descriptors.c
    msc_disk.c
    printf.c
)

target_include_directories(tinyusb
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(tinyusb
  PRIVATE
    otg_fs
    objects
    system
)
