
#ifndef ___WDT_INIT_H__
#define ___WDT_INIT_H__

#define _WDT_disable                    _wdt_stop

#define _WDT_timer_interrupt_enable    SFRIE1   |= WDTIE ; // enable WDT interrupt 


//#define _WDT_wait_interrupt_LPM3        _BIS_SR( CPUOFF + GIE ) ;
#define _WDT_wait_interrupt_LPM0        _BIS_SR( LPM0_bits + GIE ) ;
#define _WDT_wait_interrupt_LPM1        _BIS_SR( LPM1_bits + GIE ) ;
#define _WDT_wait_interrupt_LPM2        _BIS_SR( LPM2_bits + GIE ) ;
#define _WDT_wait_interrupt_LPM3        _BIS_SR( LPM3_bits + GIE ) ;
#define _WDT_wait_interrupt_LPM4        _BIS_SR( LPM4_bits + GIE ) ;
//#define _WDT_wait_interrupt_LPM0         LPM0; // if no GIE, WDT don't work.

// how to set WDTCTL ====== begin
#define _WdtDiv_31__2G               WDTIS__2G              
#define _WdtDiv_27_128M              WDTIS__128M            
#define _WdtDiv_23__8192K            WDTIS__8192K           
#define _WdtDiv_19__512K             WDTIS__512K            
#define _WdtDiv_15__32K              WDTIS__32K             
#define _WdtDiv_13__8192             WDTIS__8192            
#define _WdtDiv_9__512               WDTIS__512             
#define _WdtDiv_6__64                WDTIS__64              

// WDT is clocked by VLO (assumed 10KHz) see WDT_ADLY_1000 
// 15-8: 8 bits Wdtpw
// 7:WdtHold :  1 -> timer stop , 0 -> WDT timer run
// 6:5 : WdtSSel -> 'b00 SMCLK, 'b01 -> ACLK , 'b10 -> VLOclk, 'b11 -> X_Clk
// 4:WdtTMsel: timer modeselect : 0 -> WDT as reset mode, 1 -> WDT as timer mode
// wdtPassword + setAsTimerDisableWdtReset + clearWdtCounter + 
#define _WdtAsTimer__    (WDTPW + WDTTMSEL + WDTCNTCL) // passwd , as timer, clean counter
#define _WdtAsTimer_VLO_ (_WdtAsTimer__ + WDTSSEL__VLO)
// how to set WDTCTL ====== end

// #define Clk16384
#ifdef  Clk16384
#define ClkInit(args...)    _clk_init_16384(args)
#define Delay_1000ms()      __delay_cycles(16384)       //  1000 ms
#define Delay_100ms()       __delay_cycles(1638)        //  100  ms
#define Delay_10ms()        __delay_cycles(163)         //  10   ms
#define Delay_1ms()         __delay_cycles(16)          //  1    ms
#define Delay_250us()       __delay_cycles(4)           //  250  us
#define Delay_200us()       __delay_cycles(4)           //  250  us
#define Delay_125us()       __delay_cycles(2)           //  125  us
#define Delay_100us()       __delay_cycles(1)           //  62.5 us
#define Delay_Defined   1
#endif

#ifdef  Clk16mhz
#define ClkInit(args...)    _clk_init_16mhz(args)
#define Delay_1000ms()      __delay_cycles(16000000)    //  1000 ms
#define Delay_100ms()       __delay_cycles(1600000)     //  100  ms
#define Delay_10ms()        __delay_cycles(160000)      //  10   ms
#define Delay_1ms()         __delay_cycles(16000)       //  1    ms
#define Delay_250us()       __delay_cycles(4000)        //  250  us
#define Delay_200us()       __delay_cycles(3200)        //  200  us
#define Delay_125us()       __delay_cycles(2000)        //  125  us
#define Delay_100us()       __delay_cycles(1600)        //  100  us
#define Delay_Defined   1
#endif

#ifdef  Clk1mhz
#define ClkInit(args...)    _clk_init_16mhz(args)
#define Delay_1000ms()      __delay_cycles(1000000)     //  1000 ms
#define Delay_100ms()       __delay_cycles(100000)      //  100  ms
#define Delay_10ms()        __delay_cycles(10000)       //  10   ms
#define Delay_1ms()         __delay_cycles(1000)        //  1    ms
#define Delay_250us()       __delay_cycles(250)         //  250  us
#define Delay_200us()       __delay_cycles(200)         //  200  us
#define Delay_125us()       __delay_cycles(125)         //  125  us
#define Delay_100us()       __delay_cycles(100)         //  100  us
#define Delay_Defined   1
#endif

#ifndef Delay_Defined
#error " You must define Clk16384 or Clk16mhz, # 388348181 "
#endif

void _wdt_timer_gap_60ms_at_1Mhz_main_clk(void) ; // main clk is 1 Mhz, default, need extra-adjustment if necessary

#endif
