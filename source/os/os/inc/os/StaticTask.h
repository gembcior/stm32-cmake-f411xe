#ifndef OS_STATIC_TASK_H
#define OS_STATIC_TASK_H

#include "FreeRTOS.h"
#include "task.h"

#include <cstdint>
#include "os/Task.h"


namespace os {

class StaticTask : public Task
{
public:
  StaticTask(const char* name, uint32_t stackDepth, UBaseType_t priority, StackType_t* stack);

  StackType_t* getStack();
  StaticTask_t* getBuffer();

  virtual void run() = 0;

private:
  StackType_t* m_stack;
  StaticTask_t m_taskBuffer;
};

} // namespace

#endif /* OS_STATIC_TASK_H */
