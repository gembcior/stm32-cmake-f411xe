add_library(rcc STATIC)

target_sources(rcc
  PRIVATE
    src/RccHal.cpp
)

target_include_directories(rcc
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(rcc
  PRIVATE
    dral_stm32_f4_f411xe
)
