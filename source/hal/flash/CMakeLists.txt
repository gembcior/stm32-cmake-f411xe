add_library(flash STATIC)

target_sources(flash
  PRIVATE
    src/FlashHal.cpp
)

target_include_directories(flash
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(flash
  PRIVATE
    dral_stm32_f4_f411xe
)
