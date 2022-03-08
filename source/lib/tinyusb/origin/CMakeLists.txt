target_sources(tinyusb
  PRIVATE
    dcd_synopsys.cpp
)

target_include_directories(tinyusb
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(tinyusb
  PRIVATE
    STM32F411xE
)
