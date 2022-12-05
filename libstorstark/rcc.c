#include "gpio.h"
#include "rcc.h"
#include "pwr.h"
#include "flash.h"
#include "helper.h"

/*
#define TEST_PLL
*/

void init_clock(void)
{
    
    /* turn on HSE ***********************************************************/

    *RCC_CR |= (1<<HSEON) ;




    /* wait until HSE stable *************************************************/

    while(!(*RCC_CR & (1<<HSERDY)))
        __asm__("nop");

    *RCC_CR &= ~(1<<HSION) ;

    *RCC_APB1ENR
    |= (1<<PWREN); /* enable power interface clock */

    *PWR_CR 
    |= (1<<VOS) /* Voltage scale: Mode 3 for highest frequencies
                   1:Mode 3
                   2:Mode 2
                   3:Mode 1(reset value) */
    ;




    /*************************************************************************/

    *FLASH_ACR
    |= (1<<ICEN)
    |  (1<<DCEN)
    |  (1<<PRFTEN)
    |  (0b101<<LATENCY) /* 000: Zero wait state
                           001: One wait state        
                           010: Two wait states       
                           011: Three wait states     
                           100: Four wait states      
                           101: Five wait states      
                           110: Six wait states       
                           111: Seven wait states */  
    ;




    /* pll should be configured before enabling ******************************/

    *RCC_CFGR

    |= (8<<RTCPRE) /* feed RTC with 1MHz, divide by 8 for 8MHz HSE */

    |  (4<<PPRE2)  /* divide PLLCLK(168MHz) by 2 to get 84MHz, as the
                      maximum is 90MHz */

    |  (5<<PPRE1)  /* divide PLLCLK(168MHz) by 4 to get 42MHz, as the
                      maximum is 45MHz */

    |  (0<<HPRE)   /* AHB prescaler 0:\1 0b1000:\2... */

    |  (2<<SW);    /* select PLL as system clock */




    /* erase bits that are set on reset **************************************/

    erasebits_range(15, 3, RCC_PLLCFGR);

    *RCC_PLLCFGR

    |= (7<<PLLQ)   /* needs to be 48MHz, 336MHz/7 */

    |  (1<<PLLSRC) /* 0:HSI 1:HSE */

    |  (0<<PLLP)   /* 0:/2 1:/4 2:/6 3:/8 
                      PLLN output 336MHz/2 = 168MHz */

    |  (168<<PLLN) /* sets VCO frequency 50 <= PLLN =< 432
                      2MHz (set by PLLM) * PLLN = 336MHz
                      Has to be between 100-400MHz */
     
    |  (4<<PLLM)   /* div. factor for PLL and PLLI2S input clock (HSE or HSI)
                      2 <= PLLM =< 63
                      STElectronics recommends 2MHz to limit PLL jitter */
    ;




    /* turn on PLL ***********************************************************/

    *RCC_CR |= (1<<PLLON) ;





    /* wait for PLL to lock **************************************************/

    while(!(*RCC_CR & (1<<PLLRDY)))
        __asm__("nop");




    /* Test if PLL works correctly on MCO1 (PORTA GPIO8)
       42MHz on MCO1 for 168MHz, 168 / 4 = 42 ********************************/

#ifdef TEST_PLL
    *RCC_AHB1ENR |= (1<<GPIOAEN);
    *GPIOA_MODER |= (2<<OSPEED8);
    *GPIOA_OSPEEDR |= (3<<OSPEED8);
    *RCC_CFGR |= (3 << MCO1) /* 0 HSI, 1 LSE, 2 HSE, 3 PLL */
              |  (6 << MCO1PRE) /* 4:/2, 5:/3, 6:/4, 7:/5 */
              ;
#endif

}

