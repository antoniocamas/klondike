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
#include "../CardStackRepresenter.h"
#include "../CardStackRepresenterConsoleLinux.h"
#include "ActionController.h"
#include "ActionGame.h"
#include "MovementBuilderTextMode.h"
#include "InputManagerTextMode.h"
#include "IOConsoleLinux.h"

using namespace std;

UInterfaceConsoleLinux::UInterfaceConsoleLinux(Table * table){
	this->table = table;
	IOConsoleLinux io(this->tableElementRepresenter);
	this->io = io;
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
	io.printMessage("type C to enter a system command. \n");

	bool completeInput = false;
	vector<char> actionDescriber;

	InputManagerTextMode inputManager(this->table, this->tableElementRepresenter);

	string message = "\tEnter next movement: ";
	do{

		io.printMessage(message);
		string input = io.getInput();
		if (input == "c")
			completeInput = true;
		else
		{
			if (inputManager.isInputCorrect(input)){
				inputManager.addNewInput(input);
			}
			else
				io.printMessage("Bad Input!: \n");

			if (inputManager.isEnoughInput()){
				completeInput = true;
				MovementBuilderTextMode movementBuilder(this->table, inputManager.getUserData());
				shared_ptr<ActionGame> action(new ActionGame(this->table, movementBuilder.getMovement()));
				return action;
			}
		}

	}while(!completeInput);
}
