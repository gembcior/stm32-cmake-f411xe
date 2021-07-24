#include "os/StaticTask.h"


namespace os {

StaticTask::StaticTask(const char* name, uint32_t stackDepth, UBaseType_t priority, StackType_t* stackBuffer, StaticTask_t* taskBuffer) :

  Task(name, stackDepth, priority),
  m_stackBuffer(stackBuffer),
  m_taskBuffer(taskBuffer)
{
}


StackType_t* StaticTask::getStack()
{
  return m_stackBuffer;
}


StaticTask_t* StaticTask::getBuffer()
{
  return m_taskBuffer;
}

} // namespace
