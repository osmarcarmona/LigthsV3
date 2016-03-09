################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/adc.c" \
"../Sources/fotoresistor_adc.c" \
"../Sources/inputs.c" \
"../Sources/main.c" \
"../Sources/outputs.c" \
"../Sources/sa_mtb.c" \

C_SRCS += \
../Sources/adc.c \
../Sources/fotoresistor_adc.c \
../Sources/inputs.c \
../Sources/main.c \
../Sources/outputs.c \
../Sources/sa_mtb.c \

OBJS += \
./Sources/adc.o \
./Sources/fotoresistor_adc.o \
./Sources/inputs.o \
./Sources/main.o \
./Sources/outputs.o \
./Sources/sa_mtb.o \

C_DEPS += \
./Sources/adc.d \
./Sources/fotoresistor_adc.d \
./Sources/inputs.d \
./Sources/main.d \
./Sources/outputs.d \
./Sources/sa_mtb.d \

OBJS_QUOTED += \
"./Sources/adc.o" \
"./Sources/fotoresistor_adc.o" \
"./Sources/inputs.o" \
"./Sources/main.o" \
"./Sources/outputs.o" \
"./Sources/sa_mtb.o" \

C_DEPS_QUOTED += \
"./Sources/adc.d" \
"./Sources/fotoresistor_adc.d" \
"./Sources/inputs.d" \
"./Sources/main.d" \
"./Sources/outputs.d" \
"./Sources/sa_mtb.d" \

OBJS_OS_FORMAT += \
./Sources/adc.o \
./Sources/fotoresistor_adc.o \
./Sources/inputs.o \
./Sources/main.o \
./Sources/outputs.o \
./Sources/sa_mtb.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/adc.o: ../Sources/adc.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/adc.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/adc.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/fotoresistor_adc.o: ../Sources/fotoresistor_adc.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/fotoresistor_adc.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/fotoresistor_adc.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/inputs.o: ../Sources/inputs.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/inputs.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/inputs.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/outputs.o: ../Sources/outputs.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/outputs.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/outputs.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sa_mtb.o: ../Sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sa_mtb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/sa_mtb.o"
	@echo 'Finished building: $<'
	@echo ' '


