add_library(scb STATIC)

target_sources(scb
  PRIVATE
    src/scb_driver.cpp
)

target_include_directories(scb
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(scb
  PRIVATE
    stm32
)
