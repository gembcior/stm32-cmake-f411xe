target_sources(flasher
  PRIVATE
    Flasher.cpp
)

target_include_directories(flasher
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(flasher
  PUBLIC
    gpio
    ticktack
)
