include(Testing)

testing_target_add_test(flasher
  FlasherTest.cpp
)

testing_target_test_link_mock_libraries(flasher
  gpio
  ticktack
)
