target_sources(dma
  PRIVATE
    DmaHal.cpp
)

target_include_directories(dma
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(dma
  PRIVATE
    dral
)
