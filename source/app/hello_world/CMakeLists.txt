include(Utils)

add_executable(hello_world)

add_subdirectory(src)

stm32_target_app_release(hello_world)
