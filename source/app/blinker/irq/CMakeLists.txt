target_sources(blinker
  PRIVATE
    irq.cpp
)

target_include_directories(blinker
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
