target_sources(blinker
  PRIVATE
    hal.cpp
    flasher.cpp
    system.cpp
)

target_include_directories(blinker
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(blinker
  PRIVATE
    system
    flash
    gpio
    pwr
    rcc
    flasher
)
