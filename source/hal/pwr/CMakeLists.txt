add_library(pwr STATIC)

target_sources(pwr
  PRIVATE
    src/pwr_driver.cpp
)

target_include_directories(pwr
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(pwr
  PRIVATE
    stm32
)
