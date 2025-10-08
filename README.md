This project demonstrates bare-metal programming on the STM32H745 using GCC and a Makefile, without relying on MCU IDEs such as STM32CubeIDE or any hardware abstraction layers (HAL).
All configurations are set up manually, including the Makefile, linker script, and reset handler.
The LED blinking is controlled directly through bitwise operations on the GPIO registers.
