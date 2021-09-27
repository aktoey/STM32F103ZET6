################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/Github/STM32F103ZET6/Modules/Src/modules.c \
E:/Github/STM32F103ZET6/Modules/Src/multi_button.c \
E:/Github/STM32F103ZET6/Modules/Src/multi_timer.c 

OBJS += \
./Modules/Src/modules.o \
./Modules/Src/multi_button.o \
./Modules/Src/multi_timer.o 

C_DEPS += \
./Modules/Src/modules.d \
./Modules/Src/multi_button.d \
./Modules/Src/multi_timer.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/Src/modules.o: E:/Github/STM32F103ZET6/Modules/Src/modules.c Modules/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../../Core/Inc -I../../USB_DEVICE/App -I../../USB_DEVICE/Target -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -I../../Modules/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Modules/Src/modules.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Modules/Src/multi_button.o: E:/Github/STM32F103ZET6/Modules/Src/multi_button.c Modules/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../../Core/Inc -I../../USB_DEVICE/App -I../../USB_DEVICE/Target -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -I../../Modules/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Modules/Src/multi_button.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Modules/Src/multi_timer.o: E:/Github/STM32F103ZET6/Modules/Src/multi_timer.c Modules/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../../Core/Inc -I../../USB_DEVICE/App -I../../USB_DEVICE/Target -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -I../../Modules/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Modules/Src/multi_timer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

