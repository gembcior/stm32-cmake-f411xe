include(Testing)

stm32_target_add_test(flasher
  FlasherTest.cpp
)

stm32_target_test_link_mock_libraries(flasher
  gpio
  ticktack
)
