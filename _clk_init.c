
//#include "_include_all.h"
#include "main.h"
// _clk_init.h


void _clk_init_debug_by_oscillosope(void){
    if(1){
        P1DIR |= BIT3 ; P1SEL1 |= BIT3 ; P1SEL0 &= ~BIT3 ; // dir->1, selx->10 : link mclk  to p1.3, for oscilloscope debuging
        P1DIR |= BIT7 ; P1SEL1 |= BIT7 ; P1SEL0 &= ~BIT7 ; // dir->1, selx->10 : link smclk to p1.7, for oscilloscope debuging
        P2DIR |= BIT2 ; P2SEL1 |= BIT2 ; P2SEL0 &= ~BIT2 ; // dir->1, selx->10 : link aclk  to p2.2, for oscilloscope debuging

        P1DIR |= BIT0 ;
        while(1){
            P1OUT &= (~BIT0) ;
            P1OUT |=   BIT0  ;
        }
    }
} // _clk_init_debug_by_oscillosope

void _clk_init_16384(void){
    _wdt_hardware_reset_stop;

    _mclk_to_32768  ;
    _divm_to_2      ;
    _aclk_src_to_32768  ;

    _gpio_enable;

    __delay_cycles(16); // 0.1 second
} // _clk_init_16384

void _clk_init_32768(void){
    _wdt_hardware_reset_stop;

    _mclk_to_32768  ;
    _aclk_src_to_32768  ;

    _gpio_enable;

    __delay_cycles(33); // 0.1 second
} // _clk_init_32768

void _clk_init_1mhz( void ___gpio_init(void) ){
    _wdt_hardware_reset_stop;

    if ( ___gpio_init ) {
        ___gpio_init();
    }
    _gpio_enable;

    _clk_init_debug_by_oscillosope();

    __delay_cycles(100000); // 0.1 second
} // _clk_init_1mhz

void _clk_init_8mhz( void ___gpio_init(void) ){

    //_clk_init_16mhz(&NULL);
    _wdt_hardware_reset_stop;

    if (1){
        //8 MHZ INTERNAL CLOCK OSCILLATOR
        //disable FLL
        __bis_SR_register(SCG0);
        //Set REFO (32.768khz LFO)as FLL reference source
        CSCTL3 |= SELREF__REFOCLK;
        //clear DCO and MOD registers
        CSCTL0 = 0;
        //clear DCO frequency select bits first
        CSCTL1 &= ~(DCORSEL_7);
        //DCOFTRIM = 3, DCO Range = 8MHz
        CSCTL1 = DCOFTRIMEN + DCOFTRIM0 + DCOFTRIM1 + DCORSEL_3;
        //CSCTL1 = 0b0110111 ;
        //DCODIV = 8MHz
        CSCTL2 = FLLD_0 + 243;
        __delay_cycles(5);
        //enable FLL
        __bic_SR_register(SCG0);
        //poll until FLL is locked
        while(CSCTL7 & (FLLUNLOCK0 + FLLUNLOCK1));
        //set default REFO(~32768Hz) as ACLK source, ACLK = 32768Hz
        //default DCODIV as MCLK and SMCLK source
        CSCTL4 = SELMS__DCOCLKDIV + SELA__REFOCLK;
        //divide MCLK by 1
        CSCTL5 = DIVM__1;
        //end code
    }
    if (0){
        //Configure one FRAM wait state
        FRCTL0 = FRCTLPW + NWAITS_1;
        //disable FLL
        __bis_SR_register(SCG0);
        //Set REFO (32.768khz LFO)as FLL reference source
        CSCTL3 |= SELREF__REFOCLK;
        //clear DCO and MOD registers
        CSCTL0 = 0;
        //clear DCO frequency select bits first
        CSCTL1 &= ~(DCORSEL_7);
        //set DCO = 16MHz
        CSCTL1 = DCOFTRIMEN + DCOFTRIM0 + DCOFTRIM1 + DCORSEL_5;
        //DCOCLKDIV = 16MHz
        CSCTL2 = FLLD_0 + 487;
        __delay_cycles(5);
        //enable FLL
        __bic_SR_register(SCG0);
        //poll until FLL is locked
        while(CSCTL7 & (FLLUNLOCK0 + FLLUNLOCK1));
        //set default REFO(~32768Hz) as ACLK source, ACLK = 32768Hz
        //default DCODIV as MCLK and SMCLK source
        CSCTL4 = SELMS__DCOCLKDIV + SELA__REFOCLK;
        //divide MCLK by 1
        CSCTL5 = DIVM__1;
        //end code
    }
    if ( ___gpio_init ) {
        ___gpio_init();
    }
    _gpio_enable;

    _clk_init_debug_by_oscillosope();

    __delay_cycles(80000); // 0.1 second

} // _clk_init_8mhz

void _clk_init_16mhz( void ___gpio_init(void) ){

    _wdt_hardware_reset_stop;


    if (1){
        //Configure one FRAM wait state
        FRCTL0 = FRCTLPW + NWAITS_1;
        //disable FLL
        __bis_SR_register(SCG0);
        //Set REFO (32.768khz LFO)as FLL reference source
        CSCTL3 |= SELREF__REFOCLK;
        //clear DCO and MOD registers
        CSCTL0 = 0;
        //clear DCO frequency select bits first
        CSCTL1 &= ~(DCORSEL_7);
        //set DCO = 16MHz
        CSCTL1 = DCOFTRIMEN + DCOFTRIM0 + DCOFTRIM1 + DCORSEL_5;
        //DCOCLKDIV = 16MHz
        CSCTL2 = FLLD_0 + 487;
        __delay_cycles(5);
        //enable FLL
        __bic_SR_register(SCG0);
        //poll until FLL is locked
        while(CSCTL7 & (FLLUNLOCK0 + FLLUNLOCK1));
        //set default REFO(~32768Hz) as ACLK source, ACLK = 32768Hz
        //default DCODIV as MCLK and SMCLK source
        CSCTL4 = SELMS__DCOCLKDIV + SELA__REFOCLK;
        //divide MCLK by 1
        CSCTL5 = DIVM__1;
        //end code
    }



    if ( ___gpio_init ) {
        ___gpio_init();
    }
    _gpio_enable;

    _clk_init_debug_by_oscillosope();

    __delay_cycles(160000); // 0.1 second

} // _clk_init_16mhz
