#ifndef SCB_H
#define SCB_H

/*
   Hw adresses, names, usage description used in this file are partly or
   completely extracted from

   RM0090 Reference manual
   STM32F405/415, STM32F407/417, STM32F427/437 and
   STM32F429/439 advanced Arm®-based 32-bit MCUs

   or

   PM0214 Programming manual
   STM32 Cortex®-M4 MCUs and MPUs programming manual

   both owned by STMicroelectronics
*/

#include "bus.h"

#define SCB (PPB + 0xe000)

#define SCB_ACTLR (volatile unsigned int *)(SCB +   0x8)
#define SCB_CPUID (volatile unsigned int *)(SCB + 0xd00)
#define SCB_ICSR  (volatile unsigned int *)(SCB + 0xd04)
#define SCB_VTOR  (volatile unsigned int *)(SCB + 0xd08)
#define SCB_AIRCR (volatile unsigned int *)(SCB + 0xd0c)
#define SCB_SCR   (volatile unsigned int *)(SCB + 0xd10)
#define SCB_CCR   (volatile unsigned int *)(SCB + 0xd14)
#define SCB_SHPR1 (volatile unsigned int *)(SCB + 0xd18)
#define SCB_SHPR2 (volatile unsigned int *)(SCB + 0xd1c)
#define SCB_SHPR3 (volatile unsigned int *)(SCB + 0xd20)
#define SCB_SHCSR (volatile unsigned int *)(SCB + 0xd24)
#define SCB_CFSR  (volatile unsigned int *)(SCB + 0xd28)
/* a subregister of CFSR */
#define SCB_MMSR  (volatile unsigned int *)(SCB + 0xd28) 
#define SCB_BFSR  (volatile unsigned int *)(SCB + 0xd29)
#define SCB_UFSR  (volatile unsigned int *)(SCB + 0xd2a)
#define SCB_HFSR  (volatile unsigned int *)(SCB + 0xd2c)
#define SCB_MMAR  (volatile unsigned int *)(SCB + 0xd34)
#define SCB_BFAR  (volatile unsigned int *)(SCB + 0xd38)
#define SCB_AFSR  (volatile unsigned int *)(SCB + 0xd3c)

#endif
