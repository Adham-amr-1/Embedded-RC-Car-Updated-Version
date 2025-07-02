################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BUTTON.c \
../DIO.c \
../External_Interrupt.c \
../LCD.c \
../LED.c \
../Motors.c \
../Timers.c \
../USART.c \
../UltraSonic.c \
../main.c 

OBJS += \
./BUTTON.o \
./DIO.o \
./External_Interrupt.o \
./LCD.o \
./LED.o \
./Motors.o \
./Timers.o \
./USART.o \
./UltraSonic.o \
./main.o 

C_DEPS += \
./BUTTON.d \
./DIO.d \
./External_Interrupt.d \
./LCD.d \
./LED.d \
./Motors.d \
./Timers.d \
./USART.d \
./UltraSonic.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


