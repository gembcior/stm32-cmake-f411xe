target_sources(ticktack
  PRIVATE
    TickTack.cpp
)

target_include_directories(ticktack
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(ticktack
  PUBLIC
)
