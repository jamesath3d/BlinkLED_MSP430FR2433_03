

#ifndef __CLK_INIT_H__
#define __CLK_INIT_H__

#define _gpio_mclk_p13  P1DIR |= BIT3 ; P1SEL1 |= BIT3 ; P1SEL0 &= ~BIT3 ; // dir->1, selx->10 : link mclk  to p1.3, for oscilloscope debuging
#define _gpio_smclk_p17 P1DIR |= BIT7 ; P1SEL1 |= BIT7 ; P1SEL0 &= ~BIT7 ; // dir->1, selx->10 : link smclk to p1.7, for oscilloscope debuging
#define _gpio_aclk_p22  P2DIR |= BIT2 ; P2SEL1 |= BIT2 ; P2SEL0 &= ~BIT2 ; // dir->1, selx->10 : link aclk  to p2.2, for oscilloscope debuging


#define _wdt_reset_stop     _wdt_hardware_reset_stop       
#define _wdt_stop           _wdt_hardware_reset_stop       
#define _wdt_hardware_reset_stop       WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
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

#define _aclk_src_to_32768  CSCTL4 =   CSCTL4 |    SELA                               ; // set Aclk source to 32768 

#define _clk_to_32768  { _mclk_to_32768  ;                ; _aclk_src_to_32768  ; }
#define _clk_to_16384  { _mclk_to_32768  ; _divm_to_2     ; _aclk_src_to_32768  ; }
#define _clk_to_8192   { _mclk_to_32768  ; _divm_to_4     ; _aclk_src_to_32768  ; }
#define _clk_to_4096   { _mclk_to_32768  ; _divm_to_8     ; _aclk_src_to_32768  ; }

/* CSCTL6 Control Bits */
#define _trun_off_xt1 CSCTL6 = (CSCTL6 & (~( XT1DRIVE0 | XT1DRIVE1 ))) | XT1AGCOFF  ;

// #define SELREF0                (0x0010)       // FLL Reference Clock Select Bit : 0 
#define _set_RefCLK_32k_as_FLL_DCO_clk_source               CSCTL3 |= SELREF0               ; 
// select REFOCLK as the DCO's source.  // then default is 1Mhz of FLL's output as MCU's main clock source

void _clk_init_1mhz( void ___enable_gpio(void) );
void _clk_init_16mhz(void ___enable_gpio(void) );
void _clk_init_8mhz( void ___gpio_init(void) );

#endif
