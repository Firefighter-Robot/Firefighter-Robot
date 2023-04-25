################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include stm32_f103c6_Drivers/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include HAL/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Firefighter-Robot_Code.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Firefighter-Robot_Code.list \

OBJCOPY_BIN += \
Firefighter-Robot_Code.bin \


# All Target
all: Firefighter-Robot_Code.elf secondary-outputs

# Tool invocations
Firefighter-Robot_Code.elf: $(OBJS) $(USER_OBJS) F:\GitHub\Firefighter-Robot\Firefighter-Robot_Code\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "Firefighter-Robot_Code.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\GitHub\Firefighter-Robot\Firefighter-Robot_Code\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Firefighter-Robot_Code.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Firefighter-Robot_Code.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Firefighter-Robot_Code.list"
	@echo 'Finished building: $@'
	@echo ' '

Firefighter-Robot_Code.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Firefighter-Robot_Code.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
