/*
 * Pile2FoundationController.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: antonio
 */

#include "movement/Pile2FoundationController.h"

Pile2FoundationController::Pile2FoundationController(Table * t,
		int originPileNumber, int destinationFoundationNumber) : MovementController(t){

	this->origin = &(*this->table->getPile(originPileNumber));
	this->destination = &(*this->table->getFoundation(destinationFoundationNumber));
}

bool Pile2FoundationController::isValid() {
	if (this->origin->isEmpty())
		return false;
	const card::Card * card = this->origin->showTopCard();
	return this->destination->isPuttingDownPossible(*card);
}
