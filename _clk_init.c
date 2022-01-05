
#include "_include_all.h"
// _clk_init.h


void _clk_init_1mhz(void){
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer


    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    //    PMM_unlockLPM5();
    PM5CTL0 &= ~LOCKLPM5;

   __delay_cycles(100000); // 0.1 second
}

