target_sources(systick
  PRIVATE
    SysTickHal.cpp
)

target_include_directories(systick
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(systick
  PRIVATE
    dral
)
