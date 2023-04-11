################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/EEPROM.c \
../HAL/Keypad.c \
../HAL/LCD.c \
../HAL/Servo.c 

OBJS += \
./HAL/EEPROM.o \
./HAL/Keypad.o \
./HAL/LCD.o \
./HAL/Servo.o 

C_DEPS += \
./HAL/EEPROM.d \
./HAL/Keypad.d \
./HAL/LCD.d \
./HAL/Servo.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/EEPROM.o: ../HAL/EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/ELBOSTAN/Desktop/Drivers/HAL/inc" -I"C:/Users/ELBOSTAN/Desktop/Drivers/stm32_f103c6_Drivers/inc" -I"C:/Users/ELBOSTAN/Desktop/Drivers/stm32_f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/Keypad.o: ../HAL/Keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/ELBOSTAN/Desktop/Drivers/HAL/inc" -I"C:/Users/ELBOSTAN/Desktop/Drivers/stm32_f103c6_Drivers/inc" -I"C:/Users/ELBOSTAN/Desktop/Drivers/stm32_f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD.o: ../HAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/ELBOSTAN/Desktop/Drivers/HAL/inc" -I"C:/Users/ELBOSTAN/Desktop/Drivers/stm32_f103c6_Drivers/inc" -I"C:/Users/ELBOSTAN/Desktop/Drivers/stm32_f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/Servo.o: ../HAL/Servo.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/ELBOSTAN/Desktop/Drivers/HAL/inc" -I"C:/Users/ELBOSTAN/Desktop/Drivers/stm32_f103c6_Drivers/inc" -I"C:/Users/ELBOSTAN/Desktop/Drivers/stm32_f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Servo.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

