/*
 * ActionGame.cpp
 *
 *  Created on: Oct 21, 2017
 *      Author: antonio
 */

#include <memory>
#include "MovementController.h"
#include "ActionGame.h"

ActionGame::ActionGame(Table * t, shared_ptr<MovementController> movement): ActionController(t) {
	this->movement = movement;
};

bool ActionGame::isValid() {
	if (movement == nullptr)
		return false;
	return this->movement->isValid();
}

void ActionGame::execute() {
	this->movement->applyMovement();
}
