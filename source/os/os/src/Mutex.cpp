#include "os/Mutex.h"


namespace os {

Mutex::Mutex()
{
  m_handle = xSemaphoreCreateMutexStatic(&m_buffer);
}


bool Mutex::lock(TickType_t timeout)
{
  BaseType_t success = xSemaphoreTake(m_handle, timeout);
  return success == pdTRUE ? true : false;
}


bool Mutex::unlock()
{
  BaseType_t success = xSemaphoreGive(m_handle);
  return success == pdTRUE ? true : false;
}

} // namespace
