include(Utils)

add_executable(blinker)

add_subdirectory(src)
add_subdirectory(system)
add_subdirectory(objects)
add_subdirectory(irq)

stm32_target_app_release(blinker)
