#ifndef BUS_H
#define BUS_H

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

/* Private peripheral bus */
#define PPB 0xE0000000

#define PERIPH 0x40000000

#define APB1 (PERIPH +        0x0)
#define APB2 (PERIPH +    0x10000)
#define AHB1 (PERIPH +    0x20000)
#define AHB2 (PERIPH + 0x10000000)
#define AHB3 (PERIPH + 0x60000000)

#define GPIOA        (AHB1 +     0x0)
#define GPIOB        (AHB1 +   0x400)
#define GPIOC        (AHB1 +   0x800)
#define GPIOD        (AHB1 +   0xC00)
#define GPIOE        (AHB1 +  0x1000)
#define GPIOF        (AHB1 +  0x1400)
#define GPIOG        (AHB1 +  0x1800)
#define GPIOH        (AHB1 +  0x1c00)
#define GPIOI        (AHB1 +  0x2000)
#define GPIOJ        (AHB1 +  0x2400)
#define GPIOK        (AHB1 +  0x2800)
#define CRC          (AHB1 +  0x3000)
#define RCC          (AHB1 +  0x3800)
#define FLASH        (AHB1 +  0x3c00)
#define BKPSRAM      (AHB1 +  0x4000)
#define DMA1         (AHB1 +  0x6000)
#define DMA2         (AHB1 +  0x6400)
#define ETHERNET_MAC (AHB1 +  0x8000)
#define DMA2D        (AHB1 +  0xb000)
#define USB_OTG_HS   (AHB1 + 0x20000)

#define TIM2         (APB1 + 0x0000)
#define TIM3         (APB1 + 0x0400)
#define TIM4         (APB1 + 0x0800)
#define TIM5         (APB1 + 0x0c00)
#define TIM6         (APB1 + 0x1000)
#define TIM7         (APB1 + 0x1400)
#define TIM12        (APB1 + 0x1800)
#define TIM13        (APB1 + 0x1c00)
#define TIM14        (APB1 + 0x2000)
#define RTC          (APB1 + 0x2800)
#define WWDG         (APB1 + 0x2c00)
#define IWDG         (APB1 + 0x3000)
#define I2S2ext      (APB1 + 0x3400)
#define SPI2         (APB1 + 0x3800)
#define SPI3         (APB1 + 0x3c00)
#define I2S3ext      (APB1 + 0x4000)
#define USART2       (APB1 + 0x4400)
#define USART3       (APB1 + 0x4800)
#define UART4        (APB1 + 0x4c00)
#define UART5        (APB1 + 0x5000)
#define I2C1         (APB1 + 0x5400)
#define I2C2         (APB1 + 0x5800)
#define I2C3         (APB1 + 0x5c00)
#define CAN1         (APB1 + 0x6400)
#define CAN2         (APB1 + 0x6800)
#define PWR          (APB1 + 0x7000)
#define DAC          (APB1 + 0x7400)
#define UART7        (APB1 + 0x7800)
#define UART8        (APB1 + 0x7c00)

#endif
