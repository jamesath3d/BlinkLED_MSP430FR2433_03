
#ifndef __WDT_INIT_H__
#define __WDT_INIT_H__

#define _WDT_disable _wdt_stop

// #define Clk16384
#ifdef  Clk16384
#define ClkInit(args...)       _clk_init_16384(args)
#define Delay_1000ms()  __delay_cycles(16384)  //  1000 ms
#define Delay_100ms()   __delay_cycles(1638)   //  100  ms
#define Delay_10ms()    __delay_cycles(163)    //  10   ms
#define Delay_1ms()     __delay_cycles(16)     //  1    ms
#endif

#ifdef  Clk16mhz
#define ClkInit(args...)       _clk_init_16mhz(args)
#define Delay_1000ms()  __delay_cycles(16384)  //  1000 ms
#define Delay_100ms()   __delay_cycles(1638)   //  100  ms
#define Delay_10ms()    __delay_cycles(163)    //  10   ms
#define Delay_1ms()     __delay_cycles(16)     //  1    ms
#endif

#endif
