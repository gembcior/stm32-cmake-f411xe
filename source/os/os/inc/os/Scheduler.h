#ifndef OS_SCHEDULER_H
#define OS_SCHEDULER_H

#include "FreeRTOS.h"
#include "task.h"

#include "os/Task.h"
#include "os/StaticTask.h"


namespace os {

class Scheduler
{
public:
  inline void start();
  bool addTask(Task& task);
  bool addTask(StaticTask& task);

private:
  static void taskFunctionAdapter(void *parameters);
};



void Scheduler::start()
{
  vTaskStartScheduler();
}

} // namespace

#endif /* OS_SCHEDULER_H */
