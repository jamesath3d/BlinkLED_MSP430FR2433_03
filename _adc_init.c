
//#include "_include_all.h"
#include "main.h"

void _adc__init_p1_5(void) {

    // /home/ti/ti/ccs1040/ccs/ccs_base/msp430/include_gcc/msp430fr2433_symbols.ld
    // /home/ti/ti/ccs1040/ccs/ccs_base/msp430/include_gcc/msp430f2002_symbols.ld
    // you will find SYSCFG2 in the msp430fr2433_symbols.ld,
    // and ADC10AE0 in the msp430f2002_symbols.ld

    ADCCTL0 &= ~( ADCENC | ADCON | ADCSC ); // Disable ADC conversions , before all othere ADC registers write

    //SYSCFG2 |= ADCPCTL1 ; // ADC input A1 pin select 
    //SYSCFG2 |= ADCPCTL7 ; // ADC input A7 pin select 
    SYSCFG2 |= ADCPCTL5 ; // ADC input A5 pin select 
    // PxSEL0 = 0 ; // msp430fr2433 has no PxSEL0
    // ADC10AE0 // msp430fr2433 has no ADC10AE0

    ADCCTL0 |= ADCSHT_1 ; // bit 8-11 --> 'b0010 --> 16 ADCCLK sample hold , so total is 16 + 12 clock to get the result, about 130ms
    //ADC10CTL1 = INCH_1;                         // ADC Channel -> 1 (P1.1)
    //ADC10CTL0 = SREF_0 + ADC10SHT_3 + ADC10ON;  // Ref -> Vcc, 64 CLK S&H

    ADCCTL1 |= ADCSSEL_1  ; // 'b01 --> ACLK , ADCSSEL_1 : ADC Clock Source Select: 1 

    ADCCTL2 |= ADCRES_1; // 10-bit conversion result resolution

    /* ADCMCTL0 Control Bits */ 
    /* ADCINCH0 : ADC Input Channel Select Bit 0 */
    // ADCMCTL0 : bit 3-0 : channel select
    //ADCMCTL0 |= ADCINCH_1 // select A1 : 'b0001 --> A1 
    //ADCMCTL0 |= ADCINCH_7 // select A7 : 'b0111 --> A7 
    ADCMCTL0 |= ADCINCH_5 // select A7 : 'b0101 --> A5 
        /* ADCSREF0 : ADC Select Reference Bit 0 */
        | ADCSREF_0 ; // AVCC + AVSS , v3.3 + v0

    ADCCTL0 |= ADCON ; 

    // ADCHI
    ADCCTL0 |= ADCENC; // enable ADC conversions bit, waiting for the ADCSC's raising edge

} // _adc__init_p1_5

void _adc__init_p1_1(void) {

    ADCCTL0 &= ~( ADCENC | ADCON | ADCSC ); // Disable ADC conversions , before all othere ADC registers write

    SYSCFG2 |= ADCPCTL1 ; // ADC input A1 pin select 

    ADCCTL0 |= ADCSHT_1 ; // bit 8-11 --> 'b0010 --> 16 ADCCLK sample hold , so total is 16 + 12 clock to get the result, about 130ms

    ADCCTL1 |= ADCSSEL_1  ; // 'b01 --> ACLK , ADCSSEL_1 : ADC Clock Source Select: 1 

    ADCCTL2 |= ADCRES_1; // 10-bit conversion result resolution

    ADCMCTL0 |= ADCINCH_1 // select A1 : 'b0001 --> A1 
        /* ADCSREF0 : ADC Select Reference Bit 0 */
        | ADCSREF_0 ; // AVCC + AVSS , v3.3 + v0

    ADCCTL0 |= ADCON ; 

    // ADCHI
    ADCCTL0 |= ADCENC; // enable ADC conversions bit, waiting for the ADCSC's raising edge

} // _adc__init_p1_1

void _adc__init_p1_7(void) {

    ADCCTL0 &= ~( ADCENC | ADCON | ADCSC ); // Disable ADC conversions , before all othere ADC registers write

    SYSCFG2 |= ADCPCTL7 ; // ADC input A7 pin select 

    ADCCTL0 |= ADCSHT_1 ; // bit 8-11 --> 'b0010 --> 16 ADCCLK sample hold , so total is 16 + 12 clock to get the result, about 130ms

    ADCCTL1 |= ADCSSEL_1  ; // 'b01 --> ACLK , ADCSSEL_1 : ADC Clock Source Select: 1 

    ADCCTL2 |= ADCRES_1; // 10-bit conversion result resolution

    ADCMCTL0 |= ADCINCH_7 // select A7 : 'b0111 --> A7 
        /* ADCSREF0 : ADC Select Reference Bit 0 */
        | ADCSREF_0 ; // AVCC + AVSS , v3.3 + v0

    ADCCTL0 |= ADCON ; 

    // ADCHI
    ADCCTL0 |= ADCENC; // enable ADC conversions bit, waiting for the ADCSC's raising edge

} // _adc__init_p1_7

