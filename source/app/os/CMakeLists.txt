include(STM32Utils)

add_executable(os_app)

target_include_directories(os_app
  PRIVATE
    inc
)

target_link_libraries(os_app
  PRIVATE
    crt
    objects
    system
    irq
    uart
    flasher
    scb
    flash
    gpio
    pwr
    rcc
    systick
    nvic
    uart
    os
    os_logger
)

add_subdirectory(src)

stm32_target_app_release(os_app)
