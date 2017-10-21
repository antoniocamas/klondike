################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CardStackRepresenter.cpp \
../src/CardStackRepresenterConsoleLinux.cpp \
../src/Klondike.cpp \
../src/main.cpp 

OBJS += \
./src/CardStackRepresenter.o \
./src/CardStackRepresenterConsoleLinux.o \
./src/Klondike.o \
./src/main.o 

CPP_DEPS += \
./src/CardStackRepresenter.d \
./src/CardStackRepresenterConsoleLinux.d \
./src/Klondike.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/antonio/workspace/programming/klondike/src/view" -I"/home/antonio/workspace/programming/klondike/src/controller" -I"/home/antonio/workspace/programming/klondike/src/model" -I"/home/antonio/workspace/programming/klondike/src/model/card" -O2 -g -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


