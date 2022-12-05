#ifndef INTERRUPT_H
#define INTERRUPT_H

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

#define EXTI                          (APB2 + 0x3c00)
#define EXTI_IMR   (volatile unsigned int *)(EXTI +  0x0)
#define EXTI_EMR   (volatile unsigned int *)(EXTI +  0x4)
#define EXTI_RTSR  (volatile unsigned int *)(EXTI +  0x8)
#define EXTI_FTSR  (volatile unsigned int *)(EXTI +  0xc)
#define EXTI_SWIER (volatile unsigned int *)(EXTI + 0x10)
#define EXTI_PR    (volatile unsigned int *)(EXTI + 0x14)

/* Private peripheral bus */
#define PPB                                  0xe0000000

#define SCB_VTOR (volatile unsigned int *)(PPB + 0xed08)

/* vector table offset from 0x00000000 for use with SCV_VTOR */
#ifndef VECTOR_TABLE_BASE
#define VECTOR_TABLE_BASE 0x00000000
#endif

/* ... */
#define SYSTICK_HANDLER (void (**)(void))(VECTOR_TABLE_BASE + 0x3c)
/* ... */ 
#define EXTI0_HANDLER   (void (**)(void))(VECTOR_TABLE_BASE + 0x58)
#define EXTI1_HANDLER   (void (**)(void))(VECTOR_TABLE_BASE + 0x5c)
#define EXTI2_HANDLER   (void (**)(void))(VECTOR_TABLE_BASE + 0x60)
#define EXTI3_HANDLER   (void (**)(void))(VECTOR_TABLE_BASE + 0x64)
#define EXTI4_HANDLER   (void (**)(void))(VECTOR_TABLE_BASE + 0x68)
/* ... */


#endif

/*
 * TODO
 * 
 0  WWDF                0x00000040
 1  PVD                 0x00000044
 2  TAMP_STAMP          0x00000048
 3  RTC_WKUP            0x0000004C
 4  FLASH               0x00000050
 5  RCC                 0x00000054
 6  EXTI0               0x00000058
 7  EXTI1               0x0000005C
 8  EXTI2               0x00000060
 9  EXTI3               0x00000064
10  EXTI4               0x00000068
11  DMA1_Stream0        0x0000006C
12  DMA1_Stream1        0x00000070
13  DMA1_Stream2        0x00000074
14  DMA1_Stream3        0x00000078
15  DMA1_Stream4        0x0000007C
16  DMA1_Stream5        0x00000080
17  DMA1_Stream6        0x00000084
18  ADC                 0x00000088
19  CAN1_TX             0x0000008C
20  CAN1_RX0            0x00000090
21  CAN1_RX1            0x00000094
22  CAN1_SCE            0x00000098
23  EXTI9_5             0x0000009C
24  TIM1_BRK_TIM9       0x000000A0
25  TIM1_UP_TIM10       0x000000A4
26  TIM1_TRG_COM_TIM11  0x000000A8
27  TIM1_CC             0x000000AC
28  TIM2                0x000000B0
29  TIM3                0x000000B4
30  TIM4                0x000000B8
31  I2C1_EV             0x000000BC
32  I2C1_ER             0x000000C0
33  I2C2_EV             0x000000C4
34  I2C2_ER             0x000000C8
35  SPI1                0x000000CC
36  SPI2                0x000000D0
37  USART1              0x000000D4
38  USART2              0x000000D8
39  USART3              0x000000DC
40  EXTI15_10           0x000000E0
41  RTC_Alarm           0x000000E4
42  OTG_FS_WKUP         0x000000E8
43  TIM8_BRK_TIM12      0x000000EC
44  TIM8_UP_TIM13       0x000000F0
45  TIM8_TRG_COM_TIM14  0x000000F4
46  TIM8_CC             0x000000F8
47  DMA1_Stream7        0x000000FC
48  FSMC                0x00000100
49  SDIO                0x00000104
50  TIM5                0x00000108
51  SPI3                0x0000010C
52  UART4               0x00000110
53  UART5               0x00000114
54  TIM6_DAC            0x00000118
55  TIM7                0x0000011C
56  DMA2_Stream0        0x00000120
57  DMA2_Stream1        0x00000124
58  DMA2_Stream2        0x00000128
59  DMA2_Stream3        0x0000012C
60  DMA2_Stream4        0x00000130
61  ETH                 0x00000134
62  ETH_WKUP            0x00000138
63  CAN2_TX             0x0000013C
64  CAN2_RX0            0x00000140
65  CAN2_RX1            0x00000144
66  CAN2_SCE            0x00000148
67  OTG_FS              0x0000014C
68  DMA2_Stream5        0x00000150
69  DMA2_Stream6        0x00000154
70  DMA2_Stream7        0x00000158
71  USART6              0x0000015C
72  I2C3_EV             0x00000160
73  I2C3_ER             0x00000164
74  OTG_HS_EP0_OUT      0x00000168
75  OTG_HS_EP1_IN       0x0000016C
76  OTG_HS_WKUP         0x00000170
77  OTG_HS              0x00000174
78  DCMI                0x00000178
79  CRYP                0x0000017C
80  HASH_RNG            0x00000180
81  FPU                 0x00000184
*/

