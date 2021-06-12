target_sources(nvic
  PRIVATE
    NvicHal.cpp
)

target_include_directories(nvic
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(nvic
  PRIVATE
    dral
)
