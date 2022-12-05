#ifndef PWR_H
#define PWR_H

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

#define PWR_CR  (volatile unsigned int *)(PWR + 0x0)
#define PWR_CSR (volatile unsigned int *)(PWR + 0x4)

#define UDEN   18
#define ODSWEN 17
#define ODEN   16
#define VOS    14
#define ADCDC1 13
#define MRUDS  11
#define LPUDS  10
#define FPDS    9
#define DBP     8
#define PLS     5
#define PVDE    4
#define CSBF    3
#define CWUF    2
#define PDDS    1
#define LPDS    0

#define UDRDY   18
#define ODSWRDY 17
#define ODRDY   16
#define VOSRDY  14
#define BRE      9
#define EWUP     8
#define BRR      3
#define PVDO     2
#define SBF      1
#define WUF      0

#endif
