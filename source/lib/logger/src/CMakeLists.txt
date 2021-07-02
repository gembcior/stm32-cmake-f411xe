target_sources(logger
  PRIVATE
    Printer.cpp
    Logger.cpp
)

target_include_directories(logger
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
