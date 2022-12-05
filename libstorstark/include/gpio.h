#ifndef GPIO_H
#define GPIO_H

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

#define GPIO15 15
#define GPIO14 14
#define GPIO13 13
#define GPIO12 12
#define GPIO11 11
#define GPIO10 10
#define GPIO9   9
#define GPIO8   8
#define GPIO7   7
#define GPIO6   6
#define GPIO5   5
#define GPIO4   4
#define GPIO3   3
#define GPIO2   2
#define GPIO1   1
#define GPIO0   0

/*

GPIOx_MODER
00: Input (reset state)
01: General purpose output mode
10: Alternate function mode
11: Analog mode

GPIOx_OTYPER
0: Output push-pull (reset state)
1: Output open-drain

GPIOx_OSPEEDR
00: Low speed
01: Medium speed
10: High speed
11: Very high speed

GPIOx_PUPDR
00: No pull-up, pull-down
01: Pull-up
10: Pull-down
11: Reserved

*/

#define GPIOA_MODER   (volatile unsigned int *)(GPIOA +  0x0)
#define GPIOA_OTYPER  (volatile unsigned int *)(GPIOA +  0x4)
#define GPIOA_OSPEEDR (volatile unsigned int *)(GPIOA +  0x8)
#define GPIOA_PUPDR   (volatile unsigned int *)(GPIOA +  0xC)
#define GPIOA_IDR     (volatile unsigned int *)(GPIOA + 0x10)
#define GPIOA_ODR     (volatile unsigned int *)(GPIOA + 0x14)
#define GPIOA_BSRR    (volatile unsigned int *)(GPIOA + 0x18)
#define GPIOA_LCKR    (volatile unsigned int *)(GPIOA + 0x1C)
#define GPIOA_AFRL    (volatile unsigned int *)(GPIOA + 0x20)
#define GPIOA_AFRH    (volatile unsigned int *)(GPIOA + 0x24)


#define GPIOB_MODER   (volatile unsigned int *)(GPIOB +  0x0)
#define GPIOB_OTYPER  (volatile unsigned int *)(GPIOB +  0x4)
#define GPIOB_OSPEEDR (volatile unsigned int *)(GPIOB +  0x8)
#define GPIOB_PUPDR   (volatile unsigned int *)(GPIOB +  0xC)
#define GPIOB_IDR     (volatile unsigned int *)(GPIOB + 0x10)
#define GPIOB_ODR     (volatile unsigned int *)(GPIOB + 0x14)
#define GPIOB_BSRR    (volatile unsigned int *)(GPIOB + 0x18)
#define GPIOB_LCKR    (volatile unsigned int *)(GPIOB + 0x1C)
#define GPIOB_AFRL    (volatile unsigned int *)(GPIOB + 0x20)
#define GPIOB_AFRH    (volatile unsigned int *)(GPIOB + 0x24)

#define GPIOC_MODER   (volatile unsigned int *)(GPIOC +  0x0)
#define GPIOC_OTYPER  (volatile unsigned int *)(GPIOC +  0x4)
#define GPIOC_OSPEEDR (volatile unsigned int *)(GPIOC +  0x8)
#define GPIOC_PUPDR   (volatile unsigned int *)(GPIOC +  0xC)
#define GPIOC_IDR     (volatile unsigned int *)(GPIOC + 0x10)
#define GPIOC_ODR     (volatile unsigned int *)(GPIOC + 0x14)
#define GPIOC_BSRR    (volatile unsigned int *)(GPIOC + 0x18)
#define GPIOC_LCKR    (volatile unsigned int *)(GPIOC + 0x1C)
#define GPIOC_AFRL    (volatile unsigned int *)(GPIOC + 0x20)
#define GPIOC_AFRH    (volatile unsigned int *)(GPIOC + 0x24)

#define GPIOD_MODER   (volatile unsigned int *)(GPIOD +  0x0)
#define GPIOD_OTYPER  (volatile unsigned int *)(GPIOD +  0x4)
#define GPIOD_OSPEEDR (volatile unsigned int *)(GPIOD +  0x8)
#define GPIOD_PUPDR   (volatile unsigned int *)(GPIOD +  0xC)
#define GPIOD_IDR     (volatile unsigned int *)(GPIOD + 0x10)
#define GPIOD_ODR     (volatile unsigned int *)(GPIOD + 0x14)
#define GPIOD_BSRR    (volatile unsigned int *)(GPIOD + 0x18)
#define GPIOD_LCKR    (volatile unsigned int *)(GPIOD + 0x1C)
#define GPIOD_AFRL    (volatile unsigned int *)(GPIOD + 0x20)
#define GPIOD_AFRH    (volatile unsigned int *)(GPIOD + 0x24)

#define GPIOE_MODER   (volatile unsigned int *)(GPIOE +  0x0)
#define GPIOE_OTYPER  (volatile unsigned int *)(GPIOE +  0x4)
#define GPIOE_OSPEEDR (volatile unsigned int *)(GPIOE +  0x8)
#define GPIOE_PUPDR   (volatile unsigned int *)(GPIOE +  0xC)
#define GPIOE_IDR     (volatile unsigned int *)(GPIOE + 0x10)
#define GPIOE_ODR     (volatile unsigned int *)(GPIOE + 0x14)
#define GPIOE_BSRR    (volatile unsigned int *)(GPIOE + 0x18)
#define GPIOE_LCKR    (volatile unsigned int *)(GPIOE + 0x1C)
#define GPIOE_AFRL    (volatile unsigned int *)(GPIOE + 0x20)
#define GPIOE_AFRH    (volatile unsigned int *)(GPIOE + 0x24)

#define GPIOF_MODER   (volatile unsigned int *)(GPIOF +  0x0)
#define GPIOF_OTYPER  (volatile unsigned int *)(GPIOF +  0x4)
#define GPIOF_OSPEEDR (volatile unsigned int *)(GPIOF +  0x8)
#define GPIOF_PUPDR   (volatile unsigned int *)(GPIOF +  0xC)
#define GPIOF_IDR     (volatile unsigned int *)(GPIOF + 0x10)
#define GPIOF_ODR     (volatile unsigned int *)(GPIOF + 0x14)
#define GPIOF_BSRR    (volatile unsigned int *)(GPIOF + 0x18)
#define GPIOF_LCKR    (volatile unsigned int *)(GPIOF + 0x1C)
#define GPIOF_AFRL    (volatile unsigned int *)(GPIOF + 0x20)
#define GPIOF_AFRH    (volatile unsigned int *)(GPIOF + 0x24)

#define GPIOG_MODER   (volatile unsigned int *)(GPIOG +  0x0)
#define GPIOG_OTYPER  (volatile unsigned int *)(GPIOG +  0x4)
#define GPIOG_OSPEEDR (volatile unsigned int *)(GPIOG +  0x8)
#define GPIOG_PUPDR   (volatile unsigned int *)(GPIOG +  0xC)
#define GPIOG_IDR     (volatile unsigned int *)(GPIOG + 0x10)
#define GPIOG_ODR     (volatile unsigned int *)(GPIOG + 0x14)
#define GPIOG_BSRR    (volatile unsigned int *)(GPIOG + 0x18)
#define GPIOG_LCKR    (volatile unsigned int *)(GPIOG + 0x1C)
#define GPIOG_AFRL    (volatile unsigned int *)(GPIOG + 0x20)
#define GPIOG_AFRH    (volatile unsigned int *)(GPIOG + 0x24)

#define GPIOH_MODER   (volatile unsigned int *)(GPIOH +  0x0)
#define GPIOH_OTYPER  (volatile unsigned int *)(GPIOH +  0x4)
#define GPIOH_OSPEEDR (volatile unsigned int *)(GPIOH +  0x8)
#define GPIOH_PUPDR   (volatile unsigned int *)(GPIOH +  0xC)
#define GPIOH_IDR     (volatile unsigned int *)(GPIOH + 0x10)
#define GPIOH_ODR     (volatile unsigned int *)(GPIOH + 0x14)
#define GPIOH_BSRR    (volatile unsigned int *)(GPIOH + 0x18)
#define GPIOH_LCKR    (volatile unsigned int *)(GPIOH + 0x1C)
#define GPIOH_AFRL    (volatile unsigned int *)(GPIOH + 0x20)
#define GPIOH_AFRH    (volatile unsigned int *)(GPIOH + 0x24)

#define GPIOI_MODER   (volatile unsigned int *)(GPIOI +  0x0)
#define GPIOI_OTYPER  (volatile unsigned int *)(GPIOI +  0x4)
#define GPIOI_OSPEEDR (volatile unsigned int *)(GPIOI +  0x8)
#define GPIOI_PUPDR   (volatile unsigned int *)(GPIOI +  0xC)
#define GPIOI_IDR     (volatile unsigned int *)(GPIOI + 0x10)
#define GPIOI_ODR     (volatile unsigned int *)(GPIOI + 0x14)
#define GPIOI_BSRR    (volatile unsigned int *)(GPIOI + 0x18)
#define GPIOI_LCKR    (volatile unsigned int *)(GPIOI + 0x1C)
#define GPIOI_AFRL    (volatile unsigned int *)(GPIOI + 0x20)
#define GPIOI_AFRH    (volatile unsigned int *)(GPIOI + 0x24)

#define GPIOJ_MODER   (volatile unsigned int *)(GPIOJ +  0x0)
#define GPIOJ_OTYPER  (volatile unsigned int *)(GPIOJ +  0x4)
#define GPIOJ_OSPEEDR (volatile unsigned int *)(GPIOJ +  0x8)
#define GPIOJ_PUPDR   (volatile unsigned int *)(GPIOJ +  0xC)
#define GPIOJ_IDR     (volatile unsigned int *)(GPIOJ + 0x10)
#define GPIOJ_ODR     (volatile unsigned int *)(GPIOJ + 0x14)
#define GPIOJ_BSRR    (volatile unsigned int *)(GPIOJ + 0x18)
#define GPIOJ_LCKR    (volatile unsigned int *)(GPIOJ + 0x1C)
#define GPIOJ_AFRL    (volatile unsigned int *)(GPIOJ + 0x20)
#define GPIOJ_AFRH    (volatile unsigned int *)(GPIOJ + 0x24)

#define GPIOK_MODER   (volatile unsigned int *)(GPIOK +  0x0)
#define GPIOK_OTYPER  (volatile unsigned int *)(GPIOK +  0x4)
#define GPIOK_OSPEEDR (volatile unsigned int *)(GPIOK +  0x8)
#define GPIOK_PUPDR   (volatile unsigned int *)(GPIOK +  0xC)
#define GPIOK_IDR     (volatile unsigned int *)(GPIOK + 0x10)
#define GPIOK_ODR     (volatile unsigned int *)(GPIOK + 0x14)
#define GPIOK_BSRR    (volatile unsigned int *)(GPIOK + 0x18)
#define GPIOK_LCKR    (volatile unsigned int *)(GPIOK + 0x1C)
#define GPIOK_AFRL    (volatile unsigned int *)(GPIOK + 0x20)
#define GPIOK_AFRH    (volatile unsigned int *)(GPIOK + 0x24)

#define MODER15 30
#define MODER14 28
#define MODER13 26
#define MODER12 24
#define MODER11 22
#define MODER10 20
#define MODER9  18
#define MODER8  16
#define MODER7  14
#define MODER6  12
#define MODER5  10
#define MODER4   8
#define MODER3   6
#define MODER2   4
#define MODER1   2
#define MODER0   0

#define OT15 15
#define OT14 14
#define OT13 13
#define OT12 12
#define OT11 11
#define OT10 10
#define OT9   9
#define OT8   8
#define OT7   7
#define OT6   6
#define OT5   5
#define OT4   4
#define OT3   3
#define OT2   2
#define OT1   1
#define OT0   0

#define OSPEED15 30
#define OSPEED14 28
#define OSPEED13 26
#define OSPEED12 24
#define OSPEED11 22
#define OSPEED10 20
#define OSPEED9  18
#define OSPEED8  16
#define OSPEED7  14
#define OSPEED6  12
#define OSPEED5  10
#define OSPEED4   8
#define OSPEED3   6
#define OSPEED2   4
#define OSPEED1   2
#define OSPEED0   0

#define PUPDR15 30
#define PUPDR14 28
#define PUPDR13 26
#define PUPDR12 24
#define PUPDR11 22
#define PUPDR10 20
#define PUPDR9  18
#define PUPDR8  16
#define PUPDR7  14
#define PUPDR6  12
#define PUPDR5  10
#define PUPDR4   8
#define PUPDR3   6
#define PUPDR2   4
#define PUPDR1   2
#define PUPDR0   0

#define IDR15 15
#define IDR14 14
#define IDR13 13
#define IDR12 12
#define IDR11 11
#define IDR10 10
#define IDR9   9
#define IDR8   8
#define IDR7   7
#define IDR6   6
#define IDR5   5
#define IDR4   4
#define IDR3   3
#define IDR2   2
#define IDR1   1
#define IDR0   0

#define ODR15 15
#define ODR14 14
#define ODR13 13
#define ODR12 12
#define ODR11 11
#define ODR10 10
#define ODR9   9
#define ODR8   8
#define ODR7   7
#define ODR6   6
#define ODR5   5
#define ODR4   4
#define ODR3   3
#define ODR2   2
#define ODR1   1
#define ODR0   0

#define BR15 31
#define BR14 30
#define BR13 29
#define BR12 28
#define BR11 27
#define BR10 26
#define BR9  25
#define BR8  24
#define BR7  23
#define BR6  22
#define BR5  21
#define BR4  20
#define BR3  19
#define BR2  18
#define BR1  17
#define BR0  16
#define BS15 15
#define BS14 14
#define BS13 13
#define BS12 12
#define BS11 11
#define BS10 10
#define BS9   9
#define BS8   8
#define BS7   7
#define BS6   6
#define BS5   5
#define BS4   4
#define BS3   3
#define BS2   2
#define BS1   1
#define BS0   0

#define LCK16 16
#define LCK15 15
#define LCK14 14
#define LCK13 13
#define LCK12 12
#define LCK11 11
#define LCK10 10
#define LCK9   9
#define LCK8   8
#define LCK7   7
#define LCK6   6
#define LCK5   5
#define LCK4   4
#define LCK3   3
#define LCK2   2
#define LCK1   1
#define LCK0   0


#define AFRH15 28
#define AFRH14 24
#define AFRH13 20
#define AFRH12 16
#define AFRH11 12
#define AFRH10  8
#define AFRH9   4
#define AFRH8   0
#define AFRL7  28
#define AFRL6  24
#define AFRL5  20
#define AFRL4  16
#define AFRL3  12
#define AFRL2   8
#define AFRL1   4
#define AFRL0   0

#endif
