#ifndef REGISTER_MODEL_H
#define REGISTER_MODEL_H

#include <cstdint>

// TODO Add support for byte access and halfword access
// TODO Add support for other register policy
template <uint32_t address, uint32_t offset, uint32_t mask, typename policy>
class RegisterModel
{
public:
  static void write(uint32_t value)
  {
    policy::write(reinterpret_cast<volatile uint32_t*>(address), offset, mask, value);
  }

  static uint32_t read()
  {
    return policy::read(reinterpret_cast<volatile uint32_t*>(address), offset, mask);
  }
};


enum class RegisterPolicy {
  ReadOnly,
  WriteOnly,
  ReadWrite,
};


using FieldPolicy = RegisterPolicy;


template<RegisterPolicy regPolicy, FieldPolicy fieldPolicy>
class PolicyExecutor
{
};


template<>
class PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>
{
public:
  static uint32_t read(volatile uint32_t* reg, uint32_t offset, uint32_t mask)
  {
    return (*reg >> offset) & mask;
  }
};


template<>
class PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>
{
public:
  static void write(volatile uint32_t* reg, uint32_t offset, uint32_t mask, uint32_t value)
  {
    *reg = (value & mask) << offset;
  }
};


template<>
class PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>
{
public:
  static uint32_t read(volatile uint32_t* reg, uint32_t offset, uint32_t mask)
  {
    return (*reg >> offset) & mask;
  }
};


template<>
class PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::WriteOnly>
{
public:
  static void write(volatile uint32_t* reg, uint32_t offset, uint32_t mask, uint32_t value)
  {
    *reg = (*reg & ~(mask << offset)) | ((value & mask) << offset);
  }
};


template<>
class PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>
{
public:
  static uint32_t read(volatile uint32_t* reg, uint32_t offset, uint32_t mask)
  {
    return (*reg >> offset) & mask;
  }

  static void write(volatile uint32_t* reg, uint32_t offset, uint32_t mask, uint32_t value)
  {
    *reg = (*reg & ~(mask << offset)) | ((value & mask) << offset);
  }
};

#endif /* REGISTER_MODEL_H */
