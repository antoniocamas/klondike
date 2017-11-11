/*
 * Waste2PileController.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: antonio
 */

#include "movement/Waste2PileController.h"

#include "Card.h"
#include "Pile.h"

Waste2PileController::Waste2PileController(Table * t, int pileNumber): MovementController(t){
	this->destination = &(*this->table->getPile(pileNumber));
	this->origin = this->table->getWaste();
};

bool Waste2PileController::isValid(){
	if (this->origin->isEmpty())
		return false;
	const card::Card * card = this->origin->showTopCard();
	return this->destination->isPuttingDownPossible(*card);
}
