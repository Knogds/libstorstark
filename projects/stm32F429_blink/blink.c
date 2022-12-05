#include "rcc.h"
#include "gpio.h"

#define GREEN GPIO13
#define RED GPIO14

void sleep(int clocks);
void init_gpio(void);
void init_hw(void);

/******************************************************************************
                                         ,--.
                       ,--,--,--. ,--,--.`--',--,--,
                       |        |' ,-.  |,--.|      \
                       |  |  |  |\ '-'  ||  ||  ||  |
                       `--`--`--' `--`--'`--'`--''--'
******************************************************************************/

int main()
{
    init_hw();

    while(1){
        *GPIOG_ODR &= ~(1<<GREEN);
        *GPIOG_ODR |= (1<<RED);

        sleep(1000000);

        *GPIOG_ODR |= (1<<GREEN);
        *GPIOG_ODR &= ~(1<<RED);

        sleep(1000000);
    }

    return 0;
}

/*****************************************************************************/

void sleep(int clocks)
{
    while(clocks--)
        __asm__("nop");
}


void init_gpio(void)
{
    /* enable clock for GPIOG */
    *RCC_AHB1ENR |= (1<<GPIOGEN);

    /* setup the GPIOG [15:0] as output */
    *GPIOG_MODER = 0x55555555;
}


void init_hw(void)
{
    init_clock();
    init_gpio();
}
