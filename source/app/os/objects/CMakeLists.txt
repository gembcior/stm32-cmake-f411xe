target_sources(os_app
  PRIVATE
    hal.cpp
    lib.cpp
    system.cpp
    os.cpp
)

target_include_directories(os_app
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(os_app
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
    logger
    os
)
