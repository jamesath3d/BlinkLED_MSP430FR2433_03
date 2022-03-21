/*
 * _include_all.h
 *
 *  Created on: Aug 30, 2021
 *      Author: james
 */

#ifndef __INCLUDE_ALL_H__
#define __INCLUDE_ALL_H__

//#include <driverlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <msp430.h>
#include <gpio.h>

#include "_bit_set.h"
#include "_i2c01.h"
#include "_delay_all.h"
#include "_led_all.h"
#include "_test.h"
#include "_i2c_expander01.h"
#include "_uart_p1_5_tx_only.h"
#include "_cable_tester.h"

#include "_gpio_init.h"
#include "_clk_init.h"
#include "_wdt_init.h"

//#include "_include_all.h"

void main_init(void);

#endif /* INCLUDE_ALL_H_ */
