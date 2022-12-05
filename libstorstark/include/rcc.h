#ifndef RCC_H
#define RCC_H

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

#define RCC_CR         (volatile unsigned int *)(RCC + 0x00)
#define RCC_PLLCFGR    (volatile unsigned int *)(RCC + 0x04)
#define RCC_CFGR       (volatile unsigned int *)(RCC + 0x08)
#define RCC_CIR        (volatile unsigned int *)(RCC + 0x0c)
#define RCC_AHB1RSTR   (volatile unsigned int *)(RCC + 0x10)
#define RCC_AHB2RSTR   (volatile unsigned int *)(RCC + 0x14)
#define RCC_AHB3RSTR   (volatile unsigned int *)(RCC + 0x18)
#define RCC_APB1RSTR   (volatile unsigned int *)(RCC + 0x20)
#define RCC_APB2RSTR   (volatile unsigned int *)(RCC + 0x24)
#define RCC_AHB1ENR    (volatile unsigned int *)(RCC + 0x30)
#define RCC_AHB2ENR    (volatile unsigned int *)(RCC + 0x34)
#define RCC_AHB3ENR    (volatile unsigned int *)(RCC + 0x38)
#define RCC_APB1ENR    (volatile unsigned int *)(RCC + 0x40)
#define RCC_APB2ENR    (volatile unsigned int *)(RCC + 0x44)
#define RCC_AHB1LPENR  (volatile unsigned int *)(RCC + 0x50)
#define RCC_AHB2LPENR  (volatile unsigned int *)(RCC + 0x54)
#define RCC_AHB3LPENR  (volatile unsigned int *)(RCC + 0x58)
#define RCC_APB1LPENR  (volatile unsigned int *)(RCC + 0x60)
#define RCC_APB2LPENR  (volatile unsigned int *)(RCC + 0x64)
#define RCC_BDCR       (volatile unsigned int *)(RCC + 0x70)
#define RCC_CSR        (volatile unsigned int *)(RCC + 0x74)
#define RCC_SSCGR      (volatile unsigned int *)(RCC + 0x80)
#define RCC_PLLI2SCFGR (volatile unsigned int *)(RCC + 0x84)

/* RCC_APB1RSTR */
#define DACRST   29
#define PWRRST   28
#define CAN2RST  26
#define CAN1RST  25
#define I2C3RST  23
#define I2C2RST  22
#define I2C1RST  21
#define UART5RST 20
#define UART4RST 19
#define UART3RST 18
#define UART2RST 17
#define SPI3RST  15
#define SPI2RST  14
#define WWDGRST  11
#define TIM14RST 8
#define TIM13RST 7
#define TIM12RST 6
#define TIM7RST  5
#define TIM6RST  4
#define TIM5RST  3
#define TIM4RST  2
#define TIM3RST  1
#define TIM2RST  0

/* RCC_CR */
#define PLLI2SRDY 27
#define PLLI2SON  26
#define PLLRDY    25
#define PLLON     24
#define CSSON     19
#define HSEBYP    18
#define HSERDY    17
#define HSEON     16
#define HSICAL     8
#define HSITRIM    3
#define HSIRDY     1
#define HSION      0

/* RCC_PLLCFGR */
#define PLLQ      24
#define PLLSRC    22
#define PLLP      16
#define PLLN       6
#define PLLM       0

/* RCC_CFGR */
#define MCO2      30
#define MCO2PRE   27
#define MCO1PRE   24
#define I2SSRC    23
#define MCO1      21
#define RTCPRE    16
#define PPRE2     13
#define PPRE1     10
#define HPRE       4
#define SWS        2
#define SW         0

/* RCC_AHB1ENR */
#define OTGHSULPIEN  30
#define OTGHSEN      29
#define ETHMACPTPEN  28
#define ETHMACRXEN   27
#define ETHMACTXEN   26
#define ETHMACEN     25
#define DMA2DEN      23
#define DMA2EN       22
#define DMA1EN       21
#define CCMDATARAMEN 20
#define BKPSRAMEN    18
#define CRCEN        12
#define GPIOKEN      10
#define GPIOJEN       9
#define GPIOIEN       8
#define GPIOHEN       7
#define GPIOGEN       6
#define GPIOFEN       5
#define GPIOEEN       4
#define GPIODEN       3
#define GPIOCEN       2
#define GPIOBEN       1
#define GPIOAEN       0

/* RCC_APB1ENR */

#define DACEN    29
#define PWREN    28
#define CAN2EN   26
#define CAN1EN   25
#define I2C3EN   23
#define I2C2EN   22
#define I2C1EN   21
#define UART5EN  20
#define UART4EN  19
#define UART3EN  18
#define USART2EN 17
#define SPI3EN   15
#define SPI2EN   14
#define WWDGEN   11
#define TIM14EN   8
#define TIM13EN   7
#define TIM12EN   6
#define TIM7EN    5
#define TIM6EN    4
#define TIM5EN    3
#define TIM4EN    2
#define TIM3EN    1
#define TIM2EN    0

void init_clock(void);

#endif
