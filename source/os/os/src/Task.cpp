#include "os/Task.h"


namespace os {

Task::Task(const char* name, uint32_t stackDepth, UBaseType_t priority) :
  m_stackDepth(stackDepth),
  m_priority(priority)
{
  for (uint32_t i = 0; i < TaskNameLength; i++) {
    m_name[i] = *name;
    name++;
  }
}


const char* Task::getName()
{
  return m_name;
}


uint32_t Task::getStackDepth()
{
  return m_stackDepth;
}


UBaseType_t Task::getPriority()
{
  return m_priority;
}


TaskHandle_t* Task::getHandle()
{
  return &m_handle;
}


void Task::cleanup()
{
}

} // namespace
