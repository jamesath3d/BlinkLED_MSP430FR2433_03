

#ifndef _CLK_INIT_H
#define _CLK_INIT_H

#define _wdt_stop       WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    //    PMM_unlockLPM5();
#define _gpio_enable    PM5CTL0 &= ~LOCKLPM5;

/*
 * note : This is only available in enhanced CS systems.
 * #define SELA2                  ( SELA << 1 )
 * #define _aclk_to_10khz  CSCTL4 = ( CSCTL4 & (~(SELA | SELA2 ))) | SELA2 ; // set Aclk to 10 kHz
*/

#define _mclk_to_32768  CSCTL4 = ( CSCTL4 & (~(SELMS0 | SELMS1 | SELMS2 ))) | SELMS1 ; // set mclk & smclk to 32768 Hz
#define _divm_to_2      CSCTL5 = ( CSCTL5 & (~(DIVM2 | DIVM1 | DIVM0 ))) | SELMS0 ; // set DIVM to 2 ==> 16384
#define _aclk_to_32768  CSCTL4 =   CSCTL4 |    SELA                               ; // set Aclk to 32768 

#define _clk_to_32768  { _mclk_to_32768  ; _divm_to_2      ; _aclk_to_32768  ; }
#define _clk_to_16384  { _mclk_to_32768  ;                 ; _aclk_to_32768  ; }

void _clk_init_1mhz(void);

#endif
