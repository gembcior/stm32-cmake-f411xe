include(Utils)

add_executable(os_app)

target_include_directories(os_app
  PRIVATE
    inc
)

add_subdirectory(src)

stm32_target_app_release(os_app)
