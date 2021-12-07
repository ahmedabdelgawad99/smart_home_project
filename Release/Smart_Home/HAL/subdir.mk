################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Smart_Home/HAL/AC_Prog.c \
../Smart_Home/HAL/Door_Prog.c \
../Smart_Home/HAL/EEPROM_prog.c \
../Smart_Home/HAL/Keypad_prog.c \
../Smart_Home/HAL/LCD_prog.c \
../Smart_Home/HAL/LED_Buzzer_Prog.c \
../Smart_Home/HAL/Remote_Prog.c \
../Smart_Home/HAL/Temprature_Sensor_Prog.c 

OBJS += \
./Smart_Home/HAL/AC_Prog.o \
./Smart_Home/HAL/Door_Prog.o \
./Smart_Home/HAL/EEPROM_prog.o \
./Smart_Home/HAL/Keypad_prog.o \
./Smart_Home/HAL/LCD_prog.o \
./Smart_Home/HAL/LED_Buzzer_Prog.o \
./Smart_Home/HAL/Remote_Prog.o \
./Smart_Home/HAL/Temprature_Sensor_Prog.o 

C_DEPS += \
./Smart_Home/HAL/AC_Prog.d \
./Smart_Home/HAL/Door_Prog.d \
./Smart_Home/HAL/EEPROM_prog.d \
./Smart_Home/HAL/Keypad_prog.d \
./Smart_Home/HAL/LCD_prog.d \
./Smart_Home/HAL/LED_Buzzer_Prog.d \
./Smart_Home/HAL/Remote_Prog.d \
./Smart_Home/HAL/Temprature_Sensor_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
Smart_Home/HAL/%.o: ../Smart_Home/HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


