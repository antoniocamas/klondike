/*
 * UInterface.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include "ViewConsoleLinux.h"

#include <iostream>
#include <string>
#include <memory>

#include "CardStackViewConsoleLinux.h"
#include "InputManagerTextMode.h"
#include "IOConsoleLinux.h"
#include "MovementDescriber.h"

using namespace std;

ViewConsoleLinux::ViewConsoleLinux(): io(this->tableElementRepresenter){}

void ViewConsoleLinux::showTable() {
		card::CardStackViewConsoleLinux cardRepresenter;
	io.printHeader();

	cardRepresenter = table->getRemainderRepresenter();
	io.printRemainder(cardRepresenter.getNumberOfCardsInTheStack() > 0);

	cardRepresenter = table->getWasterRepresenter();
	io.printWaste(cardRepresenter.topCard2String(3));

	for (int i = 0; i < table->getNumberOfFundations(); ++i){
		cardRepresenter = table->getFoundationRepresenter(i);
		io.printFoundation(cardRepresenter.topCard2String(1), i+1);
	}

	io.printNewLine();
	io.printSplitter();

	for (int i = 0; i < table->getNumberOfPiles(); ++i){
			cardRepresenter = table->getPileRepresenter(i);
			io.printPile(cardRepresenter.allCard2String(), i+1);
	}
}

void ViewConsoleLinux::showWinMessage() {
	showTable();
	io.printSplitter();
	io.printMessage("\tCongratulations, you have won Klondike!!!\n");
}

MovementDescriber ViewConsoleLinux::getNextMovement() {

	io.printSplitter();

	string message = "\tEnter the ";


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

	return inputManager.getMovement();
}
