#ifndef I2C_H
#define I2C_H

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

#define I2C1_CR1   (volatile unsigned int *)(I2C1 + 0x0)
#define I2C1_CR2   (volatile unsigned int *)(I2C1 + 0x4)
#define I2C1_OAR1  (volatile unsigned int *)(I2C1 + 0x8)
#define I2C1_OAR2  (volatile unsigned int *)(I2C1 + 0xc)
#define I2C1_DR    (volatile unsigned int *)(I2C1 + 0x10)
#define I2C1_SR1   (volatile unsigned int *)(I2C1 + 0x14)
#define I2C1_SR2   (volatile unsigned int *)(I2C1 + 0x18)
#define I2C1_CCR   (volatile unsigned int *)(I2C1 + 0x1c)
#define I2C1_TRISE (volatile unsigned int *)(I2C1 + 0x20)

#define I2C2_CR1   (volatile unsigned int *)(I2C2 + 0x0)
#define I2C2_CR2   (volatile unsigned int *)(I2C2 + 0x4)
#define I2C2_OAR1  (volatile unsigned int *)(I2C2 + 0x8)
#define I2C2_OAR2  (volatile unsigned int *)(I2C2 + 0xc)
#define I2C2_DR    (volatile unsigned int *)(I2C2 + 0x10)
#define I2C2_SR1   (volatile unsigned int *)(I2C2 + 0x14)
#define I2C2_SR2   (volatile unsigned int *)(I2C2 + 0x18)
#define I2C2_CCR   (volatile unsigned int *)(I2C2 + 0x1c)
#define I2C2_TRISE (volatile unsigned int *)(I2C2 + 0x20)

#define I2C3_CR1   (volatile unsigned int *)(I2C3 + 0x0)
#define I2C3_CR2   (volatile unsigned int *)(I2C3 + 0x4)
#define I2C3_OAR1  (volatile unsigned int *)(I2C3 + 0x8)
#define I2C3_OAR2  (volatile unsigned int *)(I2C3 + 0xc)
#define I2C3_DR    (volatile unsigned int *)(I2C3 + 0x10)
#define I2C3_SR1   (volatile unsigned int *)(I2C3 + 0x14)
#define I2C3_SR2   (volatile unsigned int *)(I2C3 + 0x18)
#define I2C3_CCR   (volatile unsigned int *)(I2C3 + 0x1c)
#define I2C3_TRISE (volatile unsigned int *)(I2C3 + 0x20)

#define SWRST    15
#define ALERT    13
#define PEC_CR1  12 /* PEC (name collision) */
#define POS      11
#define ACK      10
#define STOP      9
#define START     8
#define NOSTRETCH 7
#define ENGC      6
#define ENPEC     5
#define ENARP     4
#define SMBTYPE   3
#define SMBUS     1
#define PE        0

#define LAST   12
#define DMAEN  11
#define ITEVTEN 9
#define ITERREN 8
#define FREQ    0

#define ADDMODE 15
#define ADD      0

#define ADD2   1
#define ENDUAL 0

#define DR 0

#define SMBALERT 15
#define TIMEOUT  14
#define PECERR   12
#define OVR      11
#define AF       10
#define ARLO      9
#define BERR      8
#define TxE       7
#define RxNE      6
#define STOPF     4
#define ADD10     3
#define BTF       2
#define ADDR      1
#define SB        0

#define PEC_SR2    8 /* PEC */
#define DUALF      7
#define SMBHOST    6
#define SMBDEFAULT 5
#define GENCALL    4
#define TRA        2
#define BUSY       1
#define MSL        0

#define FS   15
#define DUTY 14
#define CCR   0

#define TRISE 0

#endif
