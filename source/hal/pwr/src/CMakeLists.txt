target_sources(pwr
  PRIVATE
    PwrHal.cpp
)

target_include_directories(pwr
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(pwr
  PRIVATE
    dral
)
