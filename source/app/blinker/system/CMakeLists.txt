target_sources(blinker
  PRIVATE
    BlinkerSystem.cpp
)

target_include_directories(blinker
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(blinker
  PUBLIC
    system
    flash
    pwr
    rcc
    gpio
    systick
)
