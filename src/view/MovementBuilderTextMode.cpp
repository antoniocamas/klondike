/*
 * MovementBuilderTextMode.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: antonio
 */

#include <memory>
#include "MovementController.h"
#include "Remainder2WasteController.h"
#include "MovementBuilderTextMode.h"

MovementBuilderTextMode::MovementBuilderTextMode(Table * table, vector<string> userInput) {
	this->table = table;
	this->userInput = userInput;
}

MovementBuilderTextMode::~MovementBuilderTextMode() {
	// TODO Auto-generated destructor stub
}

shared_ptr<MovementController> MovementBuilderTextMode::getMovement() const{
	shared_ptr<MovementController> movement(new Remainder2WasteController(this->table));
	return movement;
}

