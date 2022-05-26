/*
 * _uart_p1_5_tx_only.h
 *
 *  Created on: Sep 16, 2021
 *      Author: james
 */

#ifndef __UART_P1_5_TX_ONLY_H__
#define __UART_P1_5_TX_ONLY_H__

#include "_include_all.h"

#define _UART_P1_5_TX_PUT_CH_5      _UART_P1_5_TX_PUT_CH('5') 
#define _UART_P1_5_TX_PUT_CH_A      _UART_P1_5_TX_PUT_CH('A') 
#define _UART_P1_5_TX_PUT_CH(ch) {while(!(UCA0IFG & UCTXIFG));Delay_125us();UCA0TXBUF = ch;Delay_125us();}

void _uart_p1_5_tx_only_init(void);
void _uart_p1_5_tx_only_testloop(void);

void _uart_p1_5_tx_only_put_ch(uint8_t ___hexbyte); // put char whithout change
void _uart_p1_5_tx_only_put_str(char ___hexbyte[]); // put strings
void _uart_p1_5_tx_only_put_rn(void);
void _uart_p1_5_tx_only_put_uint32(uint32_t ___uuu);    // put uint32 in hex ASCII
void _uart_p1_5_tx_only_put_uint16(uint16_t ___uuu);    // put uint16 in hex ASCII
void _uart_p1_5_tx_only_put_uint16d(uint16_t ___uuu);   // put uint16 in dec ASCII
void _uart_p1_5_tx_only_put_uint32d(uint32_t ___uuu);   // put uint32 in dec ASCII
void _uart_p1_5_tx_only_put_hex_half(uint8_t ___hexbyte); // put 0-15 in HEX ASCII  ( result 1 hex ASCII )
void _uart_p1_5_tx_only_put_hex(uint8_t ___hexbyte);      // put 0-255 in HEX ASCII ( result 2 hex ASCII )
void _uart_p1_5_tx_only_put_hex_u8(uint8_t ___hexbyte);   // put 0-255 in HEX ASCII , with "()" and dec format
void _uart_p1_5_tx_only_put_u8d(uint8_t ___hexbyte);       // put uint8 in dec ASCII
void _uart_p1_5_tx_only_put_hexS(uint8_t ___cnt , uint8_t ___hexbyte[]);
void _uart_p1_5_tx_only_loop_put_u8_by_lpm(void);

#endif /* UART_P1_5_TX_ONLY_H_ */
