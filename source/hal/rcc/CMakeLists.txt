add_library(rcc STATIC)

target_sources(rcc
  PRIVATE
    src/rcc_driver.cpp
)

target_include_directories(rcc
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(rcc
  PRIVATE
    stm32
)
