target_sources(os_app
  PRIVATE
    OsSystem.cpp
)

target_include_directories(os_app
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(os_app
  PUBLIC
    system
    flash
    pwr
    rcc
    gpio
    systick
)
