add_library(gpio STATIC)

target_sources(gpio
  PRIVATE
    src/GpioDriver.cpp
)

target_include_directories(gpio
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(gpio
  PUBLIC
    dral_stm32_f4_f411xe
)
