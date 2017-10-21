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

using namespace std;

UInterfaceConsoleLinux::~UInterfaceConsoleLinux() {
	// TODO Auto-generated destructor stub
}

void UInterfaceConsoleLinux::showTable() {
	//card::CardStackRepresenter cardRepresenter;
	card::CardStackRepresenterConsoleLinux cardRepresenter;

	cout << "\t" << "Remainder: ";

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

	MovementBuilderTextMode movementBuilder(this->table);

	string message = "\tEnter next movement: ";
	do{

		io.printMessage(message);
		string input = io.getInput();
		if (input == "c")
			completeInput = true;
		else
		{
			if (movementBuilder.isInputCorrect(input)){
				movementBuilder.addNewInput(input);
			}
			else
				io.printMessage("Bad Input!: \n");

			if (movementBuilder.isEnoughInput()){
	#include <iostream>
				cout << "in";

				completeInput = true;
				shared_ptr<ActionGame> action(new ActionGame(this->table,
						movementBuilder.getMovement()));
				return action;
			}

//			if (input[0] == 'r'){
//				completeInput = true;
//				actionDescriber.push_back(input[0]);
//			}
//			else if (input[0] == 'w'){
//				completeInput = false;
//				io.printMessage("\tWaste to: ");
//			}
//			else
//				io.printMessage("\tNot Valid Input!\n");
		}

	}while(!completeInput);
#include <iostream>
	cout << "out";
}
