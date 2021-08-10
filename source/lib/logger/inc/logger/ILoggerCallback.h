#ifndef ILOGGER_CALLBACK_H
#define ILOGGER_CALLBACK_H

namespace stm32::lib {

class ILoggerCallback
{
public:
  virtual void call() = 0;
};

} // namespace

#endif /* ILOGGER_CALLBACK_H */
