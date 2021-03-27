#ifndef ISYSTEM_H
#define ISYSTEM_H


namespace stm32::system {

class ISystem
{
public:
  virtual void initialize() = 0;

};

} // namespace

#endif /* ISYSTEM_H */
