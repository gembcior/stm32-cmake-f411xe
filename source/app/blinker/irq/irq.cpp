#include "FreeRTOS.h"
#include "task.h"
#include "irq.h"
#include "objects.h"


extern "C" void xPortSysTickHandler(void);


void NMI_Handler(void)
{
}


void HardFault_Handler(void)
{
  while (1)
  {
  }
}


void MemManage_Handler(void)
{
  while (1)
  {
  }
}


void BusFault_Handler(void)
{
  while (1)
  {
  }
}


void UsageFault_Handler(void)
{
  while (1)
  {
  }
}


//void SVC_Handler(void)
//{
//}


void DebugMon_Handler(void)
{
}


//void PendSV_Handler(void)
//{
//}


void SysTick_Handler(void)
{
  /* Clear overflow flag */
  stm32::objects::getSysTickHal().wasCountedToZero();

  if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED) {
    /* Call tick handler */
    xPortSysTickHandler();
    stm32::objects::getTickTack().tick();
  }
}
