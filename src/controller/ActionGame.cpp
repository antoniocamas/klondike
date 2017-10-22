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

ActionGame::ActionGame(Table * t, shared_ptr<MovementController> movement): ActionController(t) {
	this->movement = movement;
};
ActionGame::~ActionGame() {
	// TODO Auto-generated destructor stub
}

bool ActionGame::isValid() {
	if (movement == NULL)
		return false;
	return this->movement->isValid();
}

void ActionGame::execute() {
	this->movement->applyMovement();
}
