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
#include "CardStackView.h"
#include "ActionController.h"
#include "ActionGame.h"
#include "CardStackViewConsoleLinux.h"
#include "MovementBuilderTextMode.h"
#include "InputManagerTextMode.h"
#include "IOConsoleLinux.h"

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


shared_ptr<ActionController> ViewConsoleLinux::getAction() {

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

//void ViewConsoleLinux::getNextMovement() {
//
//	io.printSplitter();
//
//	string message = "\tEnter the ";
//
//
//	InputManagerTextMode inputManager(this->table, this->tableElementRepresenter);
//	do{
//		io.printMessage(message + inputManager.getNextExpectedElement() + ": ");
//		string input = io.getInput();
//
//		if (inputManager.isInputCorrect(input)){
//			inputManager.addNewInput(input);
//		}
//		else
//			io.printMessage("\tI coudn't understand what you mean \n");
//
//	}while(!inputManager.isEnoughInput());
//
//
//
////		if (!action->isValid())
////			io.printMessage("\t\tInvalid Movement!!\n");
//
//
//
//}
