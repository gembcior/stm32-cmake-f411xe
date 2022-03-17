include(STM32Utils)

add_executable(usb)

target_include_directories(usb
  PRIVATE
    inc
)

target_link_libraries(usb
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
    tinyusb
    otg_fs
)

add_subdirectory(src)
add_subdirectory(irq)

stm32_target_app_release(usb)
