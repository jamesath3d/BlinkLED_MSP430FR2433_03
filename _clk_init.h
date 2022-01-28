

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
 * 00b = XT1CLK with divider (must be no more than 40 kHz) // SELA -> 0
 * 01b = REFO (internal 32-kHz clock source)               // SELA -> 1
*/

#define _mclk_to_32768  CSCTL4 = ( CSCTL4 & (~(SELMS0 | SELMS1 | SELMS2 ))) | SELMS1 ; // set mclk & smclk to 32768 Hz

#define _divm_to_2      CSCTL5 = ( CSCTL5 & (~(DIVM2 | DIVM1 | DIVM0 ))) | SELMS0 ;          // set DIVM to 2 ==> 16384
#define _divm_to_4      CSCTL5 = ( CSCTL5 & (~(DIVM2 | DIVM1 | DIVM0 ))) | SELMS1 ;          // set DIVM to 4 ==>  8192
#define _divm_to_8      CSCTL5 = ( CSCTL5 & (~(DIVM2 | DIVM1 | DIVM0 ))) | SELMS1 | SELMS0 ; // set DIVM to 8 ==>  4096

#define _aclk_to_32768  CSCTL4 =   CSCTL4 |    SELA                               ; // set Aclk to 32768 

#define _clk_to_32768  { _mclk_to_32768  ;                ; _aclk_to_32768  ; }
#define _clk_to_16384  { _mclk_to_32768  ; _divm_to_2     ; _aclk_to_32768  ; }
#define _clk_to_8192   { _mclk_to_32768  ; _divm_to_4     ; _aclk_to_32768  ; }
#define _clk_to_4096   { _mclk_to_32768  ; _divm_to_8     ; _aclk_to_32768  ; }

/* CSCTL6 Control Bits */
#define _trun_off_xt1 CSCTL6 = (CSCTL6 & (~( XT1DRIVE0 | XT1DRIVE1 ))) | XT1AGCOFF  ;

void _clk_init_1mhz(void);

#endif
