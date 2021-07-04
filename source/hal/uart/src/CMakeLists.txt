target_sources(uart
  PRIVATE
    UartDriver.cpp
)

target_include_directories(uart
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(uart
  PRIVATE
    dral
)
