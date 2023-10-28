################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Timer0/Timer0_program.c 

OBJS += \
./MCAL/Timer0/Timer0_program.o 

C_DEPS += \
./MCAL/Timer0/Timer0_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Timer0/%.o: ../MCAL/Timer0/%.c MCAL/Timer0/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1600000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


