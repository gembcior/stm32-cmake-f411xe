#include <cstdint>
#include "main/main.h"
#include "rcc/rcc_driver.h"

using namespace stm32;

/**
  * @brief  Setup the microcontroller system
  *         Initialize the FPU setting, vector table location and External memory
  *         configuration.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
//  /* FPU settings ------------------------------------------------------------*/
//  #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
//    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
//  #endif
//
//  /* Configure the Vector Table location add offset address ------------------*/
//#ifdef VECT_TAB_SRAM
//  SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM */
//#else
//  SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH */
//#endif
}

int main(void)
{
  static hal::rcc::RccDriver rccDriver;
  rccDriver.enableClockSource(hal::rcc::ClockSource::Hsi);

  while (1)
  {
  }
}
