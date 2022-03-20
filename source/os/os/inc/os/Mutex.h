#ifndef OS_MUTEX_H
#define OS_MUTEX_H

#include "FreeRTOS.h"
#include "semphr.h"

#include <cstdint>


namespace os {

class Mutex
{
public:
  Mutex();
  bool lock(TickType_t timeout = portMAX_DELAY);
  bool unlock();

private:
  SemaphoreHandle_t m_handle;
  StaticSemaphore_t m_buffer;

};

} // namespace

#endif /* OS_MUTEX_H */
