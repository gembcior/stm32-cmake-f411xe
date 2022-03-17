include(STM32Utils)

add_executable(blinker)

target_include_directories(blinker
  PRIVATE
    inc
)

target_link_libraries(blinker
  PRIVATE
    crt
    objects
    system
    irq
    uart
    flasher
    logger
    scb
    flash
    gpio
    pwr
    rcc
    systick
    nvic
    uart
)

add_subdirectory(src)
add_subdirectory(irq)

stm32_target_app_release(blinker)
