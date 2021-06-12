target_sources(gpio
  PRIVATE
    GpioDriver.cpp
)

target_include_directories(gpio
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(gpio
  PUBLIC
    dral
)
