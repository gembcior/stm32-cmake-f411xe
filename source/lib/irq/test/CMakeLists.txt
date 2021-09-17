include(Testing)

stm32_target_add_test(irq
  main.cpp
  IrqTest.cpp
)
