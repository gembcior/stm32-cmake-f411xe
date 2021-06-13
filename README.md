# STM32 C++ example

## Introduction
This project is an example how software for STM32 microcontroller can be developed using pure C++.
As build system, this project use CMake.
Project also show how Googletest framework can be integrated into project for unit testing.

## Development platform
Project is develop on **XNUCLEO-F411RE** board from Waveshare manufacturer.
For build purpose Linux base system is used.

## Main features
 - Pure C++,
 - CMake build system,
 - Unit tests with Googletest framework.

## External software
List of the external software and frameworks:
 - [D-Ral](https://github.com/gembcior/d-ral) for register access,
 - [stm32-cmake-utils](https://github.com/gembcior/stm32-cmake-utils) CMake utility,
 - [Googletest](https://github.com/google/googletest) for Unit Tests.

## Requirements
 - Linux base system,
 - [CMake](https://cmake.org/) > 3.20,
 - [GNU Arm Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads).

## How to build
Clone repository
```
git clone https://github.com/gembcior/stm32-cmake-f411xe.git
```

Make build workspace directory
```
mkdir -p build
```

Go to build workspace directory
```
cd build
```

Configure CMake project and pass path to Arm toolchain
```
cmake ../stm32-cmake-f411xe -DSTM32_TOOLCHAIN=/path/to/toolchain
```

Build project
```
cmake --build .
```
