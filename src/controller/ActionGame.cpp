/*
 * ActionGame.cpp
 *
 *  Created on: Oct 21, 2017
 *      Author: antonio
 */

#include <memory>
#include "Remainder2WasteController.h"
#include "MovementController.h"
#include "ActionGame.h"

ActionGame::ActionGame(Table * t): ActionController(t) {

	shared_ptr<Remainder2WasteController> theMovement(new Remainder2WasteController(this->table));
	this->movement = theMovement;
};
ActionGame::~ActionGame() {
	// TODO Auto-generated destructor stub
}

bool ActionGame::isValid() {
	return this->movement->isValid();
}

void ActionGame::execute() {
	this->movement->applyMovement();
}
