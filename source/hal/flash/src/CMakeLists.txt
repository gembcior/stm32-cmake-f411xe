target_sources(flash
  PRIVATE
    FlashHal.cpp
)

target_include_directories(flash
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(flash
  PRIVATE
    dral_stm32_f4_f411xe
)
