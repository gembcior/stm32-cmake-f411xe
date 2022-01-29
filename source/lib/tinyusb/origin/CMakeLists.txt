target_sources(tinyusb
  PRIVATE
    dcd_synopsys.c
    usb_descriptors.c
    msc_disk.c
)

target_include_directories(tinyusb
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(tinyusb
  PRIVATE
    STM32F411xE
  PUBLIC
    LOG=2
    DEBUG=1
)
