target_sources(hello_world
  PRIVATE
    main.cpp
)

target_include_directories(hello_world
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(hello_world
  PRIVATE
    crt
)
