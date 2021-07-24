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
  Task(const char* name, uint32_t stackDepth, UBaseType_t priority);

  const char* getName();
  uint32_t getStackDepth();
  UBaseType_t getPriority();
  TaskHandle_t* getHandle();

  virtual void run() = 0;
  virtual void cleanup();

private:
  char m_name[TaskNameLength];
  uint32_t m_stackDepth;
  UBaseType_t m_priority;
  TaskHandle_t m_handle;
};

} // namespace

#endif /* OS_TASK_H */
