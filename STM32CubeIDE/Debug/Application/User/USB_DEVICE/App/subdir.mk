################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/Project/Github/STM32F103ZET6/USB_DEVICE/App/usb_device.c \
E:/Project/Github/STM32F103ZET6/USB_DEVICE/App/usbd_cdc_if.c \
E:/Project/Github/STM32F103ZET6/USB_DEVICE/App/usbd_desc.c 

OBJS += \
./Application/User/USB_DEVICE/App/usb_device.o \
./Application/User/USB_DEVICE/App/usbd_cdc_if.o \
./Application/User/USB_DEVICE/App/usbd_desc.o 

C_DEPS += \
./Application/User/USB_DEVICE/App/usb_device.d \
./Application/User/USB_DEVICE/App/usbd_cdc_if.d \
./Application/User/USB_DEVICE/App/usbd_desc.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/USB_DEVICE/App/usb_device.o: E:/Project/Github/STM32F103ZET6/USB_DEVICE/App/usb_device.c Application/User/USB_DEVICE/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../../Core/Inc -I../../USB_DEVICE/App -I../../USB_DEVICE/Target -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -I../../Modules/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/USB_DEVICE/App/usb_device.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/USB_DEVICE/App/usbd_cdc_if.o: E:/Project/Github/STM32F103ZET6/USB_DEVICE/App/usbd_cdc_if.c Application/User/USB_DEVICE/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../../Core/Inc -I../../USB_DEVICE/App -I../../USB_DEVICE/Target -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -I../../Modules/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/USB_DEVICE/App/usbd_cdc_if.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/USB_DEVICE/App/usbd_desc.o: E:/Project/Github/STM32F103ZET6/USB_DEVICE/App/usbd_desc.c Application/User/USB_DEVICE/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../../Core/Inc -I../../USB_DEVICE/App -I../../USB_DEVICE/Target -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -I../../Modules/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/USB_DEVICE/App/usbd_desc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

