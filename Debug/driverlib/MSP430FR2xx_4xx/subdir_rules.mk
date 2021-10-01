################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = /usr/bin/sh

# Each subdirectory must supply rules for building sources it contributes
driverlib/MSP430FR2xx_4xx/%.o: ../driverlib/MSP430FR2xx_4xx/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"/home/ti/ti/ccs1040/ccs/tools/compiler/msp430-gcc-9.3.1.11_linux64/bin/msp430-elf-gcc-9.3.1" -c -mmcu=msp430fr2433 -mhwmult=f5series -I"/home/ti/ti/ccs1040/ccs/ccs_base/msp430/include_gcc" -I"/home/dyn/workspace_v10/BlinkLED_MSP430FR2433_03" -I"/home/dyn/workspace_v10/BlinkLED_MSP430FR2433_03/driverlib/MSP430FR2xx_4xx" -I"/home/ti/ti/ccs1040/ccs/tools/compiler/msp430-gcc-9.3.1.11_win64/msp430-elf/include" -Og -g -gdwarf-3 -gstrict-dwarf -Wall -MMD -MP -MF"driverlib/MSP430FR2xx_4xx/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


