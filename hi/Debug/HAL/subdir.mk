################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/DC_Motor.c \
../HAL/EEPROM.c \
../HAL/Flame_Sensor.c \
../HAL/Keypad.c \
../HAL/LCD.c \
../HAL/Servo.c \
../HAL/Ultrasonic.c 

C_DEPS += \
./HAL/DC_Motor.d \
./HAL/EEPROM.d \
./HAL/Flame_Sensor.d \
./HAL/Keypad.d \
./HAL/LCD.d \
./HAL/Servo.d \
./HAL/Ultrasonic.d 

OBJS += \
./HAL/DC_Motor.o \
./HAL/EEPROM.o \
./HAL/Flame_Sensor.o \
./HAL/Keypad.o \
./HAL/LCD.o \
./HAL/Servo.o \
./HAL/Ultrasonic.o 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o HAL/%.su: ../HAL/%.c HAL/subdir.mk
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Users/refaa/STM32CubeIDE/workspace_1.4.1/hi/stm32_f103c6_Drivers/inc" -I"C:/Users/refaa/STM32CubeIDE/workspace_1.4.1/hi/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL

clean-HAL:
	-$(RM) ./HAL/DC_Motor.d ./HAL/DC_Motor.o ./HAL/DC_Motor.su ./HAL/EEPROM.d ./HAL/EEPROM.o ./HAL/EEPROM.su ./HAL/Flame_Sensor.d ./HAL/Flame_Sensor.o ./HAL/Flame_Sensor.su ./HAL/Keypad.d ./HAL/Keypad.o ./HAL/Keypad.su ./HAL/LCD.d ./HAL/LCD.o ./HAL/LCD.su ./HAL/Servo.d ./HAL/Servo.o ./HAL/Servo.su ./HAL/Ultrasonic.d ./HAL/Ultrasonic.o ./HAL/Ultrasonic.su

.PHONY: clean-HAL

