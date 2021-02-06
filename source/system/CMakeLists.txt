add_library(system STATIC)

target_sources(system
  PRIVATE
    src/System.cpp
)

target_include_directories(system
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(system
  PRIVATE
    flash
    pwr
    rcc
)
