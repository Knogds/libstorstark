#ifndef NVIC_H
#define NVIC_H

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

/* x = 0 to 7 */
#define NVIC_ISER(x)  (volatile unsigned int *)(PPB + 0xe100 + (0x04 * x))
#define NVIC_ICER(x)  (volatile unsigned int *)(PPB + 0xe180 + (0x04 * x))
#define NVIC_ISPR(x)  (volatile unsigned int *)(PPB + 0xe200 + (0x04 * x))
#define NVIC_ICPR(x)  (volatile unsigned int *)(PPB + 0xe280 + (0x04 * x))
#define NVIC_IABR(x)  (volatile unsigned int *)(PPB + 0xe300 + (0x04 * x))
#define NVIC_IPR(x)   (volatile unsigned int *)(PPB + 0xe400 + (0x04 * x))
#define NVIC_STIR     (volatile unsigned int *)(PPB + 0xee00)

/* NVIC_ISER0 interrupts 0-31 */
#define IRQ_WWDF                0
#define IRQ_PVD                 1
#define IRQ_TAMP_STAMP          2
#define IRQ_RTC_WKUP            3
#define IRQ_FLASH               4
#define IRQ_RCC                 5
#define IRQ_EXTI0               6
#define IRQ_EXTI1               7
#define IRQ_EXTI2               8
#define IRQ_EXTI3               9
#define IRQ_EXTI4              10
#define IRQ_DMA1_Stream0       11
#define IRQ_DMA1_Stream1       12
#define IRQ_DMA1_Stream2       13
#define IRQ_DMA1_Stream3       14
#define IRQ_DMA1_Stream4       15
#define IRQ_DMA1_Stream5       16
#define IRQ_DMA1_Stream6       17
#define IRQ_ADC                18
#define IRQ_CAN1_TX            19
#define IRQ_CAN1_RX0           20
#define IRQ_CAN1_RX1           21
#define IRQ_CAN1_SCE           22
#define IRQ_EXTI9_5            23
#define IRQ_TIM1_BRK_TIM9      24
#define IRQ_TIM1_UP_TIM10      25
#define IRQ_TIM1_TRG_COM_TIM11 26
#define IRQ_TIM1_CC            27
#define IRQ_TIM2               28
#define IRQ_TIM3               29
#define IRQ_TIM4               30
#define IRQ_I2C1_EV            31

#endif
