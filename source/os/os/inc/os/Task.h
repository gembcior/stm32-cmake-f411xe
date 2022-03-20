#ifndef OS_TASK_H
#define OS_TASK_H

#include "FreeRTOS.h"
#include "task.h"

#include <cstdint>


namespace os {

class Task
{
  static constexpr uint32_t TaskNameLength = 16;

public:
  Task(const char* name, uint32_t stackDepth, UBaseType_t priority, StackType_t* stackBuffer);

  const char* getName();
  uint32_t getStackDepth();
  UBaseType_t getPriority();
  TaskHandle_t* getHandle();
  StackType_t* getStack();
  StaticTask_t* getBuffer();

  virtual void run() = 0;
  void cleanup();

private:
  char m_name[TaskNameLength];
  uint32_t m_stackDepth;
  UBaseType_t m_priority;
  TaskHandle_t m_handle;
  StackType_t* m_stackBuffer;
  StaticTask_t m_taskBuffer;
};

} // namespace

#endif /* OS_TASK_H */
