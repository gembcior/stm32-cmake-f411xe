target_sources(blinker
  PRIVATE
    main.cpp
)

target_include_directories(blinker
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(blinker
  PRIVATE
    crt
    flasher
    uart
    etl
    logger
)
