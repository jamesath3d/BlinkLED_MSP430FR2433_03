#include "main.h"

void _WDT_wait_interrupt_LPM3x( uint8_t ___amount ) {
    while ( 0 != ___amount ) {
        _WDT_wait_interrupt_LPM3; 
        __nop(); 
        ___amount -- ; 
    }
} // _WDT_wait_interrupt_LPM3x
void _wdt_timer_gap_60ms_at_1Mhz_main_clk(void) { // main clk is 1 Mhz, default, need extra-adjustment if necessary

    WDTCTL = _WdtAsTimer_VLO_ | _WdtDiv_9__512 ;    // if timer_clk == VLO 8192 Hz , div 512 --> (1/8192)*512 == 0.0625 == 62.5 ms // oscilloscope 63ms


    _set_RefCLK_32k_as_FLL_DCO_clk_source ; // then default is 1Mhz of FLL's output as MCU's main clock source
    _trun_off_xt1 ; // it's no used any more

    _aclk_src_to_32768 ;

    //_clk_to_8192 ; // when VLO_60ms, 55ms WDT, 980us on/off // total 13.5ms,24%
    //_clk_to_16384 ; // when VLO_60ms, 55ms WDT, 480us on/off
    //_clk_to_32768 ; // when VLO_60ms, 55ms WDT, 240us on/off // total 3.25ms,6%

    _gpio_enable ;

    _WDT_timer_interrupt_enable ;
} // _wdt_timer_gap_60ms_at_1Mhz_main_clk

void _wdt_timer_gap_1000ms_at_1Mhz_main_clk(void) { // main clk is 1 Mhz, default, need extra-adjustment if necessary

    WDTCTL = _WdtAsTimer_VLO_ | WDTIS__8192 ;    // if timer_clk == VLO 8192 Hz , div 8192 --> (1/8192)*8192 == 1s == 1000 ms // oscilloscope 63ms


    _set_RefCLK_32k_as_FLL_DCO_clk_source ; // then default is 1Mhz of FLL's output as MCU's main clock source
    _trun_off_xt1 ; // it's no used any more

    _aclk_src_to_32768 ;

    //_clk_to_8192 ; // when VLO_60ms, 55ms WDT, 980us on/off // total 13.5ms,24%
    //_clk_to_16384 ; // when VLO_60ms, 55ms WDT, 480us on/off
    //_clk_to_32768 ; // when VLO_60ms, 55ms WDT, 240us on/off // total 3.25ms,6%

    _gpio_enable ;

    _WDT_timer_interrupt_enable ;
} // _wdt_timer_gap_1000ms_at_1Mhz_main_clk

