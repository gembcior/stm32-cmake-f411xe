target_sources(system
  PRIVATE
    System.cpp
)

target_include_directories(system
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(system
  PUBLIC
    flash
    pwr
    rcc
    gpio
    systick
)
