################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/BUZZER/buzzer.c 

OBJS += \
./HAL/BUZZER/buzzer.o 

C_DEPS += \
./HAL/BUZZER/buzzer.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/BUZZER/%.o: ../HAL/BUZZER/%.c HAL/BUZZER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\lenovo\eclipse_workspace_2022\EXTI_project\HAL\BUZZER" -I"C:\Users\lenovo\eclipse_workspace_2022\EXTI_project\MCAL\TIMER" -I"C:\Users\lenovo\eclipse_workspace_2022\EXTI_project\MCAL\ADC" -I"C:\Users\lenovo\eclipse_workspace_2022\EXTI_project\LIB" -I"C:\Users\lenovo\eclipse_workspace_2022\EXTI_project\MCAL\EXTI" -I"C:\Users\lenovo\eclipse_workspace_2022\EXTI_project\MCAL\GIE" -I"C:\Users\lenovo\eclipse_workspace_2022\EXTI_project\MCAL\EXTI" -I"C:\Users\lenovo\eclipse_workspace_2022\EXTI_project\MCAL\DIO" -I"C:\Users\lenovo\eclipse_workspace_2022\EXTI_project\MCAL" -I"C:\Users\lenovo\eclipse_workspace_2022\EXTI_project\HAL\KEYPAD" -I"C:\Users\lenovo\eclipse_workspace_2022\EXTI_project\HAL\LCD" -I"C:\Users\lenovo\eclipse_workspace_2022\EXTI_project\HAL\LED" -I"C:\Users\lenovo\eclipse_workspace_2022\EXTI_project\HAL\SSD" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


