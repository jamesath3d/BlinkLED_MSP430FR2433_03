
#include "_include_all.h"

void _gpio_init()
{
    P1DIR = 0xFF; 
    P2DIR = 0xFF; 
    P3DIR = 0xFF;

    P1REN = 0xFF; 
    P2REN = 0xFF; 
    P3REN = 0xFF;

    P1OUT = 0x00; 
    P2OUT = 0x00; 
    P3OUT = 0x00;
}
