#include "rcc.h"
#include "gpio.h"

#define RED_ATUSB GPIO5
#define GREEN GPIO12
#define ORANGE GPIO13
#define RED GPIO14
#define BLUE GPIO15

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
        *GPIOD_ODR &= ~((1<<RED_ATUSB)
                      | (1<<GREEN)
                      | (1<<ORANGE)
                      | (1<<RED)
                      | (1<<BLUE));

        sleep(5000000);

        *GPIOD_ODR |= (1<<RED_ATUSB)
                    | (1<<GREEN)
                    | (1<<ORANGE)
                    | (1<<RED)
                    | (1<<BLUE);

        sleep(5000000);
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
    /* enable clock for GPIOD */
    *RCC_AHB1ENR |= (1<<GPIODEN);

    /* setup the GPIOD [15:0] as output */
    *GPIOD_MODER = 0x55555555;
}


void init_hw(void)
{
    init_clock();
    init_gpio();
}
