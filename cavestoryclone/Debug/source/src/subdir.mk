################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/src/game.cpp \
../source/src/graphics.cpp \
../source/src/input.cpp \
../source/src/main.cpp 

OBJS += \
./source/src/game.o \
./source/src/graphics.o \
./source/src/input.o \
./source/src/main.o 

CPP_DEPS += \
./source/src/game.d \
./source/src/graphics.d \
./source/src/input.d \
./source/src/main.d 


# Each subdirectory must supply rules for building sources it contributes
source/src/%.o: ../source/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/udichje/Repo/c/cavestoryclone/source/header" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


