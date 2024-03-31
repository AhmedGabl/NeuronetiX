################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/PORT/PORT.c \
../MCAL/PORT/PORT_cnf.c 

OBJS += \
./MCAL/PORT/PORT.o \
./MCAL/PORT/PORT_cnf.o 

C_DEPS += \
./MCAL/PORT/PORT.d \
./MCAL/PORT/PORT_cnf.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/PORT/%.o: ../MCAL/PORT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


