target_sources(scb
  PRIVATE
    ScbHal.cpp
)

target_include_directories(scb
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(scb
  PRIVATE
    dral_stm32_f4_f411xe
)
