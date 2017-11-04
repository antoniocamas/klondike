/*
 * UInterface.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include <iostream>
#include <string>
#include <memory>
#include "UInterfaceConsoleLinux.h"
#include "CardStackView.h"
#include "ActionController.h"
#include "ActionGame.h"
#include "CardStackViewConsoleLinux.h"
#include "MovementBuilderTextMode.h"
#include "InputManagerTextMode.h"
#include "IOConsoleLinux.h"

using namespace std;

UInterfaceConsoleLinux::UInterfaceConsoleLinux(Table * table):table(table), io(this->tableElementRepresenter){
}

UInterfaceConsoleLinux::~UInterfaceConsoleLinux() {
	// TODO Auto-generated destructor stub
}

void UInterfaceConsoleLinux::showTable() {
	//card::CardStackRepresenter cardRepresenter;
	card::CardStackRepresenterConsoleLinux cardRepresenter;

	io.printHeader();
	cardRepresenter = table->getRemainderRepresenter();
	io.printRemainder(cardRepresenter.getNumberOfCardsInTheStack() > 0);
	cardRepresenter = table->getWasterRepresenter();
	io.printWaste(cardRepresenter.topCard2String(3));

	for (int i = 0; i < table->getNumberOfFundations(); ++i){
		cardRepresenter = table->getFoundationRepresenter(i);
		io.printFoundation(cardRepresenter.topCard2String(), i+1);
	}

	io.printNewLine();
	io.printSplitter();

	for (int i = 0; i < table->getNumberOfPiles(); ++i){
			cardRepresenter = table->getPileRepresenter(i);
			io.printPile(cardRepresenter.allCard2String(), i+1);
	}
}

shared_ptr<ActionController> UInterfaceConsoleLinux::getAction() {

	io.printSplitter();

	shared_ptr<ActionGame> action = NULL;
	string message = "\tEnter the ";

	do{
		InputManagerTextMode inputManager(this->table, this->tableElementRepresenter);
		do{
			io.printMessage(message + inputManager.getNextExpectedElement() + ": ");
			string input = io.getInput();

			if (inputManager.isInputCorrect(input)){
					inputManager.addNewInput(input);
			}
			else
				io.printMessage("\tI coudn't understand what you mean \n");

		}while(!inputManager.isEnoughInput());

		MovementBuilderTextMode movementBuilder(this->table,
				inputManager.getUserData(),	this->tableElementRepresenter);
		shared_ptr<MovementController> movement = movementBuilder.getMovement();
		action = make_shared<ActionGame>(this->table, movement);

		if (!action->isValid())
			io.printMessage("\t\tInvalid Movement!!\n");

	}while(!action->isValid());

	return action;
}
