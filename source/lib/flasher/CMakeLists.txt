add_library(flasher STATIC)

target_sources(flasher
  PRIVATE
    src/Flasher.cpp
)

target_include_directories(flasher
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(flasher
  PUBLIC
    gpio
)
