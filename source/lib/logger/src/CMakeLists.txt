target_sources(logger
  PRIVATE
    Logger.cpp
)

target_include_directories(logger
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(logger
  PUBLIC
    uart
)
