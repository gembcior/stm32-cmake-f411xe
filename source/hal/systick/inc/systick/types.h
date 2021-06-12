#ifndef SYS_TICK_TYPES_H
#define SYS_TICK_TYPES_H

namespace stm32::hal {

enum class SysTickClockSource {
  AhbDiv8,
  Ahb,
};

} // namespace

#endif /* SYS_TICK_TYPES_H */
