
#include "rcc.h"
#include "i2c.h"
#include "gpio.h"

#define LED_RED_ATUSB ODR5
#define LED_GREEN ODR12
#define LED_ORANGE ODR13
#define LED_RED ODR14
#define LED_BLUE ODR15

void sleep(unsigned int clocks);
void init_leds(void);
void init_hw(void);
void init_CS43L22(void);
void send_CS43L22(int *data, int data_length);
void receive_CS43L22(int address);
void led_on(int led);
void led_off(int led);
void blink(int led);
void i2c_waitbusy(void);
void test_gpiob(void);

int main()
{
    init_hw();

    int beep_freq_on_time[] = {0x1c,
                               0,1,2,3,2,2,2,2};

    send_CS43L22(beep_freq_on_time, 9);

    receive_CS43L22(0x22); /* Headphone Volume Control HPA */

    while(1){ blink(1<<LED_GREEN);
    }

//    receive_CS43L22(0x23); /* Headphone Volume Control HPB */


    while(1){}

    return 0;
}
void sleep(unsigned int clocks)
{
    while(clocks--)
        __asm__("nop");
}
void init_leds(void)
{
    /* enable clock for GPIOD */
    *RCC_AHB1ENR |= (1<<GPIODEN);


    /* set GPIOD 5,12,13,14,15 as output */
    *GPIOD_MODER |= (1<<MODER5)
                 | (1<<MODER12)
                 | (1<<MODER13)
                 | (1<<MODER14)
                 | (1<<MODER15);
}
void init_CS43L22(void)
{

/*  CS43L22
    ---------
    PB6 SCL
    PB9 SDA
    PD4 RESET 
    ---------
    Max clock is 100 kHz
    chip address: 0x94
    chip address when transmitting to master: 0x95
    CS43L22 is acting as slave */
    /* not needed: NEEE!!!
    *RCC_APB1RSTR |= (1<<I2C1RST);*/
    /* Enable clock for GPIOB and GPIOD */
    *RCC_AHB1ENR |= (1<<GPIOBEN) | (1<<GPIODEN);
    /* Enable clock for i2c */
    *RCC_APB1ENR |= (1<<I2C1EN);
    /* Set GPIOD4 (CS43L22 reset) as output */
    *GPIOD_MODER |= (1<<MODER4);
    /* Hold reset low */
    *GPIOD_ODR &= ~(1<<ODR4);
    /* Pullup on SCL and SDA */
    *GPIOB_PUPDR |= (1<<PUPDR6) | (1<<PUPDR9);
    /* SCL and SDA must be configured as open-drain */
    *GPIOB_OTYPER |= (1<<OT6) | (1<<OT9);
    /* Alternative function mode for PB6 and PB9 */
    *GPIOB_MODER |= (2<<MODER6) | (2<<MODER9);
    /* Set PB6 and PB9 as alternative function AF4 - i2c */
    *GPIOB_AFRL |= (4<<AFRL6);
    *GPIOB_AFRH |= (4<<AFRH9);

    /* Do the following only while the i2c is *disabled*!
     . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */
    /* Disable i2c */
    *I2C1_CR1 &= ~(1<<PE);
    /* Configure peripheral clock to 2MHz (Minimum for 100kHz i2c is 2MHz) */
    *I2C1_CR2 |= (2<<FREQ);
    /* Configure CCR, for Sm (Standard Mode, 100kHz)
       T_PCLK1 = APB1 clock in ns (not in us!) = 1000/168 = 5.9ns
       T_hi = 5000ms = CCR * T_PCLK1
       T_lo = 5000ms = CCR * T_PCLK1
       846 * 5.9 = cca 5000ms */
    //*I2C1_CCR = (846<<CCR);
    *I2C1_CCR = (0x28<<CCR); // u uputama
    /* Configure rise time. Max rise time for 100kHz i2c is 1us
       (1000ns / T_PCLK1) + 1 = (1000 / 5.9) + 1 = 169 + 1 = 170 */
    /* erase TRISE[5:0] as the reset state is not 0 */
    *I2C1_TRISE &= ~(0b111111); 
    //*I2C1_TRISE |= (170<<TRISE);
    *I2C1_TRISE |= (0x9<<TRISE); // u uputama
    /* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . */
    /* enable i2c */
    *I2C1_CR1 |= (1<<PE);
    /* Bring reset high */
    *GPIOD_ODR |= (1<<ODR4);
}
void send_CS43L22(int *data, int data_length)
{
    /* Generate a start condition */
    *I2C1_CR1 |= (1<<START);
    //while(*I2C1_SR2 & (1<<BUSY)){}
    while(!(*I2C1_SR1 & (1<<SB))){}      // EV5
    while(!(*I2C1_SR1 & (1<<SB))){}      // EV5
    *I2C1_DR |= 0x94 & 0xff;             // Address
    while(!(*I2C1_SR1 & (1<<ADDR))){}    // EV6
    volatile int tmp_sr2  = *I2C1_SR2;   // EV6
    while(!(*I2C1_SR1 & (1<<TxE))){}     // EV8_1
    /* Send data */
    while(data_length--){
        *I2C1_DR = *data++ & 0xff;
        while(!(*I2C1_SR1 & (1<<TxE))){} // EV8
    }
    while(!(*I2C1_SR1 & ((1<<TxE)|(1<<BTF)))){} // EV8_2
    *I2C1_CR1 |= (1<<STOP);
}
void receive_CS43L22(int address)
{
    int tmp;
    int *adr = address;
    send_CS43L22(adr, 1);
    *I2C1_CR1 |= (1<<START);             // S
    while(!(*I2C1_SR1 & (1<<SB))){}      // EV5
    while(!(*I2C1_SR1 & (1<<SB))){}      // EV5
    *I2C1_DR |= 0x95 & 0xff;             // Address
    while(!(*I2C1_SR1 & (1<<ADDR))){}    // EV6
    volatile int tmp_sr2  = *I2C1_SR2;   // EV6
    /* Send data */
    while(1){
        tmp = *I2C1_DR;
        while(!(*I2C1_SR1 & (1<<RxNE))){} // EV8
    }
}
void init_hw(void)
{
    init_clock();
    init_leds();
    init_CS43L22();
}
void led_on(int led)
{
    *GPIOD_ODR |= led;
}
void led_off(int led)
{
    *GPIOD_ODR &= ~(led);
}
void blink(int led)
{
    led_on(led);
    sleep(10000000);
    led_off(led);
    sleep(10000000);
}
void test_gpiob(void)
{
    *RCC_AHB1ENR |= (1<<GPIOBEN);
    *GPIOB_MODER |= (1<<MODER6) | (1<<MODER9);
    while(1){
        *GPIOB_ODR &= ~((1<<ODR6) | (1<<ODR9));
        sleep(100);
        *GPIOB_ODR |= (1<<ODR6) | (1<<ODR9);
        sleep(100);
    }
}


