################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Card.cpp \
../src/Deck.cpp \
../src/Klondike.cpp \
../src/TableLayout.cpp \
../src/UInterface.cpp \
../src/main.cpp 

OBJS += \
./src/Card.o \
./src/Deck.o \
./src/Klondike.o \
./src/TableLayout.o \
./src/UInterface.o \
./src/main.o 

CPP_DEPS += \
./src/Card.d \
./src/Deck.d \
./src/Klondike.d \
./src/TableLayout.d \
./src/UInterface.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


