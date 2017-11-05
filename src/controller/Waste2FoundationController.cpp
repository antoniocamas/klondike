/*
 * Waste2FoundationController.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: antonio
 */

#include "Waste2FoundationController.h"

Waste2FoundationController::Waste2FoundationController(Table * t, int foundationNumber): MovementController(t){
	this->destination = &(*this->table->getFoundation(foundationNumber));
	this->origin = this->table->getWaste();
}

bool Waste2FoundationController::isValid() {
	if (this->origin->isEmpty())
		return false;
	const card::Card * card = this->origin->showTopCard();
	return this->destination->isPuttingDownPossible(*card);
}
