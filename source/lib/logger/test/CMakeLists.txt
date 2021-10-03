include(Testing)

stm32_target_add_test(logger
  main.cpp
  LoggerOutputBuffer.cpp
  PrinterTest.cpp
  LoggerTest.cpp
)


stm32_target_test_link_mock_libraries(logger
  logger
)

add_executable(logger_app
  app.cpp
)

target_include_directories(logger_app
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(logger_app
  PRIVATE
    logger
)
