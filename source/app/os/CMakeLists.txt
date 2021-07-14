include(Utils)

add_executable(os_app)

add_subdirectory(src)
add_subdirectory(system)
add_subdirectory(objects)
add_subdirectory(irq)

stm32_target_app_release(os_app)
