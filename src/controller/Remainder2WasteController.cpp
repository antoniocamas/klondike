/*
 * Remainder2WasteController.cpp
 *
 *  Created on: Oct 21, 2017
 *      Author: antonio
 */

#include "CardStack.h"
#include "Remainder2WasteController.h"

Remainder2WasteController::Remainder2WasteController(Table * t): MovementController(t){
	this->destination = this->table->getWaste();
	this->origin = this->table->getRemainder();
};


Remainder2WasteController::~Remainder2WasteController() {
	// TODO Auto-generated destructor stub
}

bool Remainder2WasteController::isValid() {
	return !this->origin->isEmpty();
}

