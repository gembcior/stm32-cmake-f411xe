#include "os/Scheduler.h"

#include "FreeRTOS.h"
#include "task.h"


namespace os {

bool Scheduler::addTask(Task& task)
{
  BaseType_t status = pdFAIL;

// TODO disabled - no support for dynamic allocation
//  status = xTaskCreate(taskFunctionAdapter,
//                       task.getName(),
//                       task.getStackDepth(),
//                       &task,
//                       task.getPriority(),
//                       task.getHandle());

  return status != pdPASS ? false : true;
}


bool Scheduler::addTask(StaticTask& task)
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
