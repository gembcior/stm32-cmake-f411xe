#include "os/Scheduler.h"

#include "FreeRTOS.h"
#include "task.h"


namespace os {

bool Scheduler::addTask(Task& task)
{
  TaskHandle_t handle = xTaskCreateStatic(taskFunctionAdapter,
                                          task.getName(),
                                          task.getStackDepth(),
                                          &task,
                                          task.getPriority(),
                                          task.getStack(),
                                          task.getBuffer());
  *task.getHandle() = handle;

  return handle == nullptr ? false : true;
}


void Scheduler::taskFunctionAdapter(void *parameters)
{
  Task* task = static_cast<Task*>(parameters);
  task->run();
  task->cleanup();
  vTaskDelete(*task->getHandle());
}

} // namespace
