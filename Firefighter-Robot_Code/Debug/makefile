################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include stm32_f103c6_Drivers/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include HAL/subdir.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Firefighter-Robot_Code
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Firefighter-Robot_Code.axf \

MAP_FILES += \
Firefighter-Robot_Code.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Firefighter-Robot_Code.list \

OBJCOPY_HEX += \
Firefighter-Robot_Code.hex \

OBJCOPY_BIN += \
Firefighter-Robot_Code.bin \

OBJCOPY_VERILOG += \
Firefighter-Robot_Code.verilog \

OBJCOPY_SREC += \
Firefighter-Robot_Code.srec \


# All Target
all: main-build

# Main-build Target
main-build: Firefighter-Robot_Code.axf secondary-outputs

# Tool invocations
Firefighter-Robot_Code.axf Firefighter-Robot_Code.map: $(OBJS) $(USER_OBJS) D:\FireFighterRobot\Firefighter-Robot\Firefighter-Robot_Code\STM32F103C6TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc  -gdwarf-2 -o "Firefighter-Robot_Code.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\FireFighterRobot\Firefighter-Robot\Firefighter-Robot_Code\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Firefighter-Robot_Code.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Firefighter-Robot_Code.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Firefighter-Robot_Code.list"
	@echo 'Finished building: $@'
	@echo ' '

Firefighter-Robot_Code.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Firefighter-Robot_Code.hex"
	@echo 'Finished building: $@'
	@echo ' '

Firefighter-Robot_Code.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Firefighter-Robot_Code.bin"
	@echo 'Finished building: $@'
	@echo ' '

Firefighter-Robot_Code.verilog: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O verilog $(EXECUTABLES) "Firefighter-Robot_Code.verilog"
	@echo 'Finished building: $@'
	@echo ' '

Firefighter-Robot_Code.srec: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O srec $(EXECUTABLES) "Firefighter-Robot_Code.srec"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Firefighter-Robot_Code.axf Firefighter-Robot_Code.bin Firefighter-Robot_Code.hex Firefighter-Robot_Code.list Firefighter-Robot_Code.map Firefighter-Robot_Code.srec Firefighter-Robot_Code.verilog default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN) $(OBJCOPY_VERILOG) $(OBJCOPY_SREC)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
