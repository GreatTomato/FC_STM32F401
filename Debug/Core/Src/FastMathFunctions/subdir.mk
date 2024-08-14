################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/FastMathFunctions/arm_vexp_f32.c \
../Core/Src/FastMathFunctions/arm_vlog_f32.c 

OBJS += \
./Core/Src/FastMathFunctions/arm_vexp_f32.o \
./Core/Src/FastMathFunctions/arm_vlog_f32.o 

C_DEPS += \
./Core/Src/FastMathFunctions/arm_vexp_f32.d \
./Core/Src/FastMathFunctions/arm_vlog_f32.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/FastMathFunctions/%.o Core/Src/FastMathFunctions/%.su Core/Src/FastMathFunctions/%.cyclo: ../Core/Src/FastMathFunctions/%.c Core/Src/FastMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-FastMathFunctions

clean-Core-2f-Src-2f-FastMathFunctions:
	-$(RM) ./Core/Src/FastMathFunctions/arm_vexp_f32.cyclo ./Core/Src/FastMathFunctions/arm_vexp_f32.d ./Core/Src/FastMathFunctions/arm_vexp_f32.o ./Core/Src/FastMathFunctions/arm_vexp_f32.su ./Core/Src/FastMathFunctions/arm_vlog_f32.cyclo ./Core/Src/FastMathFunctions/arm_vlog_f32.d ./Core/Src/FastMathFunctions/arm_vlog_f32.o ./Core/Src/FastMathFunctions/arm_vlog_f32.su

.PHONY: clean-Core-2f-Src-2f-FastMathFunctions

