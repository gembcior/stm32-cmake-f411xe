#include "os/StaticTask.h"


namespace os {

StaticTask::StaticTask(const char* name, uint32_t stackDepth, UBaseType_t priority, StackType_t* stack) :
  Task(name, stackDepth, priority),
  m_stack(stack)
{
}


StackType_t* StaticTask::getStack()
{
  return m_stack;
}


StaticTask_t* StaticTask::getBuffer()
{
  return &m_taskBuffer;
}

} // namespace
