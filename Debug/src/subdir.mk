################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Card.cpp \
../src/CardStack.cpp \
../src/Deck.cpp \
../src/Foundation.cpp \
../src/Klondike.cpp \
../src/Pile.cpp \
../src/Suit.cpp \
../src/TableLayout.cpp \
../src/UInterface.cpp \
../src/main.cpp 

OBJS += \
./src/Card.o \
./src/CardStack.o \
./src/Deck.o \
./src/Foundation.o \
./src/Klondike.o \
./src/Pile.o \
./src/Suit.o \
./src/TableLayout.o \
./src/UInterface.o \
./src/main.o 

CPP_DEPS += \
./src/Card.d \
./src/CardStack.d \
./src/Deck.d \
./src/Foundation.d \
./src/Klondike.d \
./src/Pile.d \
./src/Suit.d \
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


