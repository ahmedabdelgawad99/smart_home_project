################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Smart_Home/MCAL/ADC_Prog.c \
../Smart_Home/MCAL/DIO_prog.c \
../Smart_Home/MCAL/GIE_Prog.c \
../Smart_Home/MCAL/IIC_prog.c \
../Smart_Home/MCAL/Interrupt_Prog.c \
../Smart_Home/MCAL/Timer0_Prog.c \
../Smart_Home/MCAL/Timer_Servo_Prog.c \
../Smart_Home/MCAL/USART_Prog.c 

OBJS += \
./Smart_Home/MCAL/ADC_Prog.o \
./Smart_Home/MCAL/DIO_prog.o \
./Smart_Home/MCAL/GIE_Prog.o \
./Smart_Home/MCAL/IIC_prog.o \
./Smart_Home/MCAL/Interrupt_Prog.o \
./Smart_Home/MCAL/Timer0_Prog.o \
./Smart_Home/MCAL/Timer_Servo_Prog.o \
./Smart_Home/MCAL/USART_Prog.o 

C_DEPS += \
./Smart_Home/MCAL/ADC_Prog.d \
./Smart_Home/MCAL/DIO_prog.d \
./Smart_Home/MCAL/GIE_Prog.d \
./Smart_Home/MCAL/IIC_prog.d \
./Smart_Home/MCAL/Interrupt_Prog.d \
./Smart_Home/MCAL/Timer0_Prog.d \
./Smart_Home/MCAL/Timer_Servo_Prog.d \
./Smart_Home/MCAL/USART_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
Smart_Home/MCAL/%.o: ../Smart_Home/MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


