target_sources(os_app
  PRIVATE
    main.cpp
)

target_include_directories(os_app
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(os_app
  PRIVATE
    crt
    flasher
    uart
    etl
    logger
    os
)
