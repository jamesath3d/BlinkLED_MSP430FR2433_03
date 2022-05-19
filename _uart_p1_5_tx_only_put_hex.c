/*
 * _uart_p1_5_tx_only.c
 *
 *  Created on: Sep 16, 2021
 *      Author: james
 */

//#include "_uart_p1_5_tx_only.h"
#include "main.h"

void _uart_p1_5_tx_only_put_rn(void){
    _UART_P1_5_TX_PUT_CH('\r');
    _UART_P1_5_TX_PUT_CH('\n');
} // _uart_p1_5_tx_only_put_rn

void _uart_p1_5_tx_only_put_uint32(uint32_t ___uuu){
    uint32_t __uu;
    uint8_t  __u;
    uint8_t  __ii;
    _UART_P1_5_TX_PUT_CH(' ');
    for ( __ii = 4 ; __ii > 0 ; __ii --) {
        __uu = 0xff000000 & ___uuu ;
        __uu >>=24 ;
        __u = __uu & 0xff;
        ___uuu <<=8;
        _uart_p1_5_tx_only_put_hex(__u);
    }
    //_UART_P1_5_TX_PUT_CH(' ');
} // _uart_p1_5_tx_only_put_uint32

void _uart_p1_5_tx_only_put_uint16(uint16_t ___uuu){
    uint8_t  __u;
    _UART_P1_5_TX_PUT_CH(' ');

    __u = ( ___uuu >> 8 ) & 0xFF ;
    _uart_p1_5_tx_only_put_hex(__u);

    __u = ___uuu & 0xFF ;
    _uart_p1_5_tx_only_put_hex(__u);

    //_UART_P1_5_TX_PUT_CH(' ');
} // _uart_p1_5_tx_only_put_uint16


void _uart_p1_5_tx_only_put_hex_half(uint8_t ___hexhalf){
    ___hexhalf &= 0xf;
    if ( ___hexhalf >= 10 ) {
        ___hexhalf += ('A' - 10 );
    } else {
        ___hexhalf += '0' ;
    }
    _UART_P1_5_TX_PUT_CH(___hexhalf);
} // _uart_p1_5_tx_only_put_hex_half

void _uart_p1_5_tx_only_put_hex(uint8_t ___hexbyte){
    uint8_t __hex;
    __hex = 0xf0 & ___hexbyte;
    __hex >>=4;
    _uart_p1_5_tx_only_put_hex_half( __hex );
    _uart_p1_5_tx_only_put_hex_half( ___hexbyte );
} // _uart_p1_5_tx_only_put_hex

void _uart_p1_5_tx_only_put_hex_u8(uint8_t ___hexbyte){
    _uart_p1_5_tx_only_put_hex(___hexbyte);
    _uart_p1_5_tx_only_put_ch('(');
    _uart_p1_5_tx_only_put_u8d(___hexbyte);
    _uart_p1_5_tx_only_put_ch(')');
} // _uart_p1_5_tx_only_put_hex_u8

void _uart_p1_5_tx_only_put_hexS(uint8_t ___cnt , uint8_t ___hexbyte[]){
    int8_t  __ii;
    for ( __ii = 0 ; __ii < ___cnt ; __ii ++) {
        if (__ii != 0 && 0 == __ii % 2 ) {
            _uart_p1_5_tx_only_put_ch('_');
        }
        _uart_p1_5_tx_only_put_hex(___hexbyte[__ii]);
    }
} // _uart_p1_5_tx_only_put_hexS

void _uart_p1_5_tx_only_put_ch(uint8_t ___ch){
    _UART_P1_5_TX_PUT_CH( ___ch );
} // _uart_p1_5_tx_only_put_ch

void _uart_p1_5_tx_only_put_str(char ___str[]){
    char * __lp;
    char   __c;

    __lp = &(___str[0]);
    while ( 0 != __lp ) {
        __c = (*__lp);
        if (0 == __c) {
            break ;
        }
        _UART_P1_5_TX_PUT_CH(__c);
        __lp ++;
    }
} // _uart_p1_5_tx_only_put_str

void _uart_p1_5_tx_only_put_uint32d(uint32_t ___uuu){
    uint8_t  __i;
    uint8_t  __u;
    uint8_t  __en;
    uint32_t  __x1;
    uint32_t  __x2;

    _UART_P1_5_TX_PUT_CH(' ');

    if ( 0 == ___uuu ) {
        _UART_P1_5_TX_PUT_CH('0');
    } else {
        //__x1 = 0x2710 ; // 10000d
        __x1 = 0x3b9aca00 ; // 1000000000d
        __en = 0 ;
        for ( __i = 10 ; __i > 0 ; __i -- ) {
            __x2 = ___uuu / __x1 ;
            __u = __x2 & 0xF;
            if ( 0 == __u ) {
                if ( __en ) {
                    _UART_P1_5_TX_PUT_CH('0');
                }
            } else {
                _uart_p1_5_tx_only_put_hex_half(__u);
                __en = 1 ;
            }
            ___uuu -= __x1 * __u ; 
            __x1 /= 10 ;
        }
    }

    //_UART_P1_5_TX_PUT_CH(' ');
} // _uart_p1_5_tx_only_put_uint32d

void _uart_p1_5_tx_only_put_uint16d(uint16_t ___uuu){
    uint8_t  __i;
    uint8_t  __u;
    uint8_t  __en;
    uint16_t  __x1;
    uint16_t  __x2;

    _UART_P1_5_TX_PUT_CH(' ');

    if ( 0 == ___uuu ) {
        _UART_P1_5_TX_PUT_CH('0');
    } else {
        __x1 = 0x2710 ; // 10000d
        __en = 0 ;
        for ( __i = 5 ; __i > 0 ; __i -- ) {
            __x2 = ___uuu / __x1 ;
            __u = __x2 & 0xF;
            if ( 0 == __u ) {
                if ( __en ) {
                    _UART_P1_5_TX_PUT_CH('0');
                }
            } else {
                _uart_p1_5_tx_only_put_hex_half(__u);
                __en = 1 ;
            }
            ___uuu -= __x1 * __u ; 
            __x1 /= 10 ;
        }
    }

    //_UART_P1_5_TX_PUT_CH(' ');
} // _uart_p1_5_tx_only_put_uint16d

void _uart_p1_5_tx_only_put_u8d(uint8_t ___hexbyte){
    uint8_t __tt;

    _UART_P1_5_TX_PUT_CH(' ');
    __tt=0;
    if( ___hexbyte >= 100 ) {
        __tt = ___hexbyte - 100 ;
        if( __tt >= 100 ) {
            _uart_p1_5_tx_only_put_hex_half(2);
            ___hexbyte -= 200;
        } else {
            _uart_p1_5_tx_only_put_hex_half(1);
            ___hexbyte -= 100;
        }
    }
    if( ___hexbyte >= 10 ) {
        __tt = ___hexbyte / 10;
        _uart_p1_5_tx_only_put_hex_half(__tt);
        ___hexbyte -= (10 * __tt);
    } else {
        if ( 0 != __tt ) {
            _uart_p1_5_tx_only_put_hex_half(0);
        }
    }
    _uart_p1_5_tx_only_put_hex_half(___hexbyte);
    //_UART_P1_5_TX_PUT_CH(' ');
} // _uart_p1_5_tx_only_put_u8d

