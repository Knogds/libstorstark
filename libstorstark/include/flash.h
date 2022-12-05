#ifndef FLASH_H
#define FLASH_H

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

#define FLASH_ACR     (volatile unsigned int *)(FLASH + 0x00)
#define FLASH_KEYR    (volatile unsigned int *)(FLASH + 0x04)
#define FLASH_OPTKEYR (volatile unsigned int *)(FLASH + 0x08)
#define FLASH_SR      (volatile unsigned int *)(FLASH + 0x0c)
#define FLASH_CR      (volatile unsigned int *)(FLASH + 0x10)
#define FLASH_OPTCR   (volatile unsigned int *)(FLASH + 0x14)

#define DCRST  12
#define ICRST  11
#define DCEN   10
#define ICEN    9
#define PRFTEN  8
#define LATENCY 0

#endif
