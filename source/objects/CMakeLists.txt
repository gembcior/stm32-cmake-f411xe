add_library(objects STATIC)

target_sources(objects
  PRIVATE
    src/hal.cpp
    src/system.cpp
    src/flasher.cpp
)

target_include_directories(objects
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(objects
  PUBLIC
    system
    flash
    gpio
    pwr
    rcc
    flasher
)
