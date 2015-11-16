################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../naive_suffix_array.cpp 

OBJS += \
./naive_suffix_array.o 

CPP_DEPS += \
./naive_suffix_array.d 


# Each subdirectory must supply rules for building sources it contributes
naive_suffix_array.o: ../naive_suffix_array.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"naive_suffix_array.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


