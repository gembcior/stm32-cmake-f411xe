target_sources(blinker
  PRIVATE
    hal.cpp
    lib.cpp
    system.cpp
)

target_include_directories(blinker
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(blinker
  PRIVATE
    flash
    gpio
    pwr
    rcc
    systick
    nvic
    flasher
    ticktack
    uart
)
