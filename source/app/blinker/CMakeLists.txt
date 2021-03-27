include(Utils)

add_executable(blinker)

add_subdirectory(src)
add_subdirectory(objects)

stm32_target_app_release(blinker)
