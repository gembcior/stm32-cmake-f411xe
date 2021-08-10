include(Utils)

add_executable(blinker)

target_include_directories(blinker
  PRIVATE
    inc
)

add_subdirectory(src)
add_subdirectory(irq)

stm32_target_app_release(blinker)
