################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../msp430fr2433.ld 

C_SRCS += \
../_bit_set.c \
../_cable_tester_mainloop_once.c \
../_delay_1ms.c \
../_delay_1s.c \
../_delay_1us.c \
../_i2c01_clk_to_0.c \
../_i2c01_clk_to_1.c \
../_i2c01_init.c \
../_i2c01_sda_to_0.c \
../_i2c01_sda_to_1.c \
../_i2c_expander01_check_sda1.c \
../_i2c_expander01_r1w0_6.c \
../_i2c_expander01_read6.c \
../_i2c_expander01_reset.c \
../_i2c_expander01_testLoop.c \
../_led_green_set_output.c \
../_led_green_toggle.c \
../_led_red_set_output.c \
../_led_red_toggle.c \
../_test001.c \
../_test002.c \
../_test003.c \
../_uart_p1_5_tx_only_init.c \
../_uart_p1_5_tx_only_put_hex.c \
../_uart_p1_5_tx_only_testloop.c \
../main.c \
../main_init.c 

C_DEPS += \
./_bit_set.d \
./_cable_tester_mainloop_once.d \
./_delay_1ms.d \
./_delay_1s.d \
./_delay_1us.d \
./_i2c01_clk_to_0.d \
./_i2c01_clk_to_1.d \
./_i2c01_init.d \
./_i2c01_sda_to_0.d \
./_i2c01_sda_to_1.d \
./_i2c_expander01_check_sda1.d \
./_i2c_expander01_r1w0_6.d \
./_i2c_expander01_read6.d \
./_i2c_expander01_reset.d \
./_i2c_expander01_testLoop.d \
./_led_green_set_output.d \
./_led_green_toggle.d \
./_led_red_set_output.d \
./_led_red_toggle.d \
./_test001.d \
./_test002.d \
./_test003.d \
./_uart_p1_5_tx_only_init.d \
./_uart_p1_5_tx_only_put_hex.d \
./_uart_p1_5_tx_only_testloop.d \
./main.d \
./main_init.d 

OBJS += \
./_bit_set.o \
./_cable_tester_mainloop_once.o \
./_delay_1ms.o \
./_delay_1s.o \
./_delay_1us.o \
./_i2c01_clk_to_0.o \
./_i2c01_clk_to_1.o \
./_i2c01_init.o \
./_i2c01_sda_to_0.o \
./_i2c01_sda_to_1.o \
./_i2c_expander01_check_sda1.o \
./_i2c_expander01_r1w0_6.o \
./_i2c_expander01_read6.o \
./_i2c_expander01_reset.o \
./_i2c_expander01_testLoop.o \
./_led_green_set_output.o \
./_led_green_toggle.o \
./_led_red_set_output.o \
./_led_red_toggle.o \
./_test001.o \
./_test002.o \
./_test003.o \
./_uart_p1_5_tx_only_init.o \
./_uart_p1_5_tx_only_put_hex.o \
./_uart_p1_5_tx_only_testloop.o \
./main.o \
./main_init.o 

OBJS__QUOTED += \
"_bit_set.o" \
"_cable_tester_mainloop_once.o" \
"_delay_1ms.o" \
"_delay_1s.o" \
"_delay_1us.o" \
"_i2c01_clk_to_0.o" \
"_i2c01_clk_to_1.o" \
"_i2c01_init.o" \
"_i2c01_sda_to_0.o" \
"_i2c01_sda_to_1.o" \
"_i2c_expander01_check_sda1.o" \
"_i2c_expander01_r1w0_6.o" \
"_i2c_expander01_read6.o" \
"_i2c_expander01_reset.o" \
"_i2c_expander01_testLoop.o" \
"_led_green_set_output.o" \
"_led_green_toggle.o" \
"_led_red_set_output.o" \
"_led_red_toggle.o" \
"_test001.o" \
"_test002.o" \
"_test003.o" \
"_uart_p1_5_tx_only_init.o" \
"_uart_p1_5_tx_only_put_hex.o" \
"_uart_p1_5_tx_only_testloop.o" \
"main.o" \
"main_init.o" 

C_DEPS__QUOTED += \
"_bit_set.d" \
"_cable_tester_mainloop_once.d" \
"_delay_1ms.d" \
"_delay_1s.d" \
"_delay_1us.d" \
"_i2c01_clk_to_0.d" \
"_i2c01_clk_to_1.d" \
"_i2c01_init.d" \
"_i2c01_sda_to_0.d" \
"_i2c01_sda_to_1.d" \
"_i2c_expander01_check_sda1.d" \
"_i2c_expander01_r1w0_6.d" \
"_i2c_expander01_read6.d" \
"_i2c_expander01_reset.d" \
"_i2c_expander01_testLoop.d" \
"_led_green_set_output.d" \
"_led_green_toggle.d" \
"_led_red_set_output.d" \
"_led_red_toggle.d" \
"_test001.d" \
"_test002.d" \
"_test003.d" \
"_uart_p1_5_tx_only_init.d" \
"_uart_p1_5_tx_only_put_hex.d" \
"_uart_p1_5_tx_only_testloop.d" \
"main.d" \
"main_init.d" 

C_SRCS__QUOTED += \
"../_bit_set.c" \
"../_cable_tester_mainloop_once.c" \
"../_delay_1ms.c" \
"../_delay_1s.c" \
"../_delay_1us.c" \
"../_i2c01_clk_to_0.c" \
"../_i2c01_clk_to_1.c" \
"../_i2c01_init.c" \
"../_i2c01_sda_to_0.c" \
"../_i2c01_sda_to_1.c" \
"../_i2c_expander01_check_sda1.c" \
"../_i2c_expander01_r1w0_6.c" \
"../_i2c_expander01_read6.c" \
"../_i2c_expander01_reset.c" \
"../_i2c_expander01_testLoop.c" \
"../_led_green_set_output.c" \
"../_led_green_toggle.c" \
"../_led_red_set_output.c" \
"../_led_red_toggle.c" \
"../_test001.c" \
"../_test002.c" \
"../_test003.c" \
"../_uart_p1_5_tx_only_init.c" \
"../_uart_p1_5_tx_only_put_hex.c" \
"../_uart_p1_5_tx_only_testloop.c" \
"../main.c" \
"../main_init.c" 


