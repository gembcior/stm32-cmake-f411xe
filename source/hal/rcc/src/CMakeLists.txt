target_sources(rcc
  PRIVATE
    RccHal.cpp
)

target_include_directories(rcc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(rcc
  PRIVATE
    dral
)
