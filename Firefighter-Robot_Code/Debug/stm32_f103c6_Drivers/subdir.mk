################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32_f103c6_Drivers/delay.c \
../stm32_f103c6_Drivers/stm32_f103c6_ADC.c \
../stm32_f103c6_Drivers/stm32_f103c6_EXTI.c \
../stm32_f103c6_Drivers/stm32_f103c6_GPIO.c \
../stm32_f103c6_Drivers/stm32_f103c6_I2C.c \
../stm32_f103c6_Drivers/stm32_f103c6_RCC.c \
../stm32_f103c6_Drivers/stm32_f103c6_SPI.c \
../stm32_f103c6_Drivers/stm32_f103c6_TIM2_3.c \
../stm32_f103c6_Drivers/stm32_f103c6_USART.c 

C_DEPS += \
./stm32_f103c6_Drivers/delay.d \
./stm32_f103c6_Drivers/stm32_f103c6_ADC.d \
./stm32_f103c6_Drivers/stm32_f103c6_EXTI.d \
./stm32_f103c6_Drivers/stm32_f103c6_GPIO.d \
./stm32_f103c6_Drivers/stm32_f103c6_I2C.d \
./stm32_f103c6_Drivers/stm32_f103c6_RCC.d \
./stm32_f103c6_Drivers/stm32_f103c6_SPI.d \
./stm32_f103c6_Drivers/stm32_f103c6_TIM2_3.d \
./stm32_f103c6_Drivers/stm32_f103c6_USART.d 

OBJS += \
./stm32_f103c6_Drivers/delay.o \
./stm32_f103c6_Drivers/stm32_f103c6_ADC.o \
./stm32_f103c6_Drivers/stm32_f103c6_EXTI.o \
./stm32_f103c6_Drivers/stm32_f103c6_GPIO.o \
./stm32_f103c6_Drivers/stm32_f103c6_I2C.o \
./stm32_f103c6_Drivers/stm32_f103c6_RCC.o \
./stm32_f103c6_Drivers/stm32_f103c6_SPI.o \
./stm32_f103c6_Drivers/stm32_f103c6_TIM2_3.o \
./stm32_f103c6_Drivers/stm32_f103c6_USART.o 


# Each subdirectory must supply rules for building sources it contributes
stm32_f103c6_Drivers/%.o stm32_f103c6_Drivers/%.su: ../stm32_f103c6_Drivers/%.c stm32_f103c6_Drivers/subdir.mk
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"D:/FireFighterRobot/Firefighter-Robot/Firefighter-Robot_Code/stm32_f103c6_Drivers/inc" -I"D:/FireFighterRobot/Firefighter-Robot/Firefighter-Robot_Code/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-stm32_f103c6_Drivers

clean-stm32_f103c6_Drivers:
	-$(RM) ./stm32_f103c6_Drivers/delay.d ./stm32_f103c6_Drivers/delay.o ./stm32_f103c6_Drivers/delay.su ./stm32_f103c6_Drivers/stm32_f103c6_ADC.d ./stm32_f103c6_Drivers/stm32_f103c6_ADC.o ./stm32_f103c6_Drivers/stm32_f103c6_ADC.su ./stm32_f103c6_Drivers/stm32_f103c6_EXTI.d ./stm32_f103c6_Drivers/stm32_f103c6_EXTI.o ./stm32_f103c6_Drivers/stm32_f103c6_EXTI.su ./stm32_f103c6_Drivers/stm32_f103c6_GPIO.d ./stm32_f103c6_Drivers/stm32_f103c6_GPIO.o ./stm32_f103c6_Drivers/stm32_f103c6_GPIO.su ./stm32_f103c6_Drivers/stm32_f103c6_I2C.d ./stm32_f103c6_Drivers/stm32_f103c6_I2C.o ./stm32_f103c6_Drivers/stm32_f103c6_I2C.su ./stm32_f103c6_Drivers/stm32_f103c6_RCC.d ./stm32_f103c6_Drivers/stm32_f103c6_RCC.o ./stm32_f103c6_Drivers/stm32_f103c6_RCC.su ./stm32_f103c6_Drivers/stm32_f103c6_SPI.d ./stm32_f103c6_Drivers/stm32_f103c6_SPI.o ./stm32_f103c6_Drivers/stm32_f103c6_SPI.su ./stm32_f103c6_Drivers/stm32_f103c6_TIM2_3.d ./stm32_f103c6_Drivers/stm32_f103c6_TIM2_3.o ./stm32_f103c6_Drivers/stm32_f103c6_TIM2_3.su ./stm32_f103c6_Drivers/stm32_f103c6_USART.d ./stm32_f103c6_Drivers/stm32_f103c6_USART.o ./stm32_f103c6_Drivers/stm32_f103c6_USART.su

.PHONY: clean-stm32_f103c6_Drivers

