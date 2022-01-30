target_sources(tinyusb
  PRIVATE
    port.cpp
)

target_include_directories(tinyusb
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(tinyusb
  PRIVATE
    otg_fs
    objects
)
