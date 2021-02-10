include(Utils)

add_executable(main)

target_sources(main
  PRIVATE
    src/main.cpp
)

target_include_directories(main
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(main
  PRIVATE
    crt
    system
    objects
    flasher
)

stm32_target_app_release(main)
link_compile_commands_file(main)
