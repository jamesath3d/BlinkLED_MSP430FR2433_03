
#include "_include_all.h"

void _gpio_init()
{
    // PxDIR : 0 -> set as input, 1 -> set as output
    P1DIR = 0xFF; 
    P2DIR = 0xFF; 
    P3DIR = 0xFF;

    // PxREN : 0 -> pull up/down resistor disabled , 1 -> pull up/down resistor enabled 
    P1REN = 0xFF; 
    P2REN = 0xFF; 
    P3REN = 0xFF;

    // PxOUT : 0 -> Output is low, 1 -> Output is high
    P1OUT = 0x00; 
    P2OUT = 0x00; 
    P3OUT = 0x00;
}
