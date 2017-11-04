/*
 * Pile2PileController.cpp
 *
 *  Created on: Nov 4, 2017
 *      Author: antonio
 */

#include "Pile2PileController.h"

Pile2PileController::Pile2PileController(Table * t, int originPileNumber, int destinationPileNumber,
		Card originCard): MovementController(t), originCard(originCard) {

	this->origin = &(*this->table->getPile(originPileNumber));
	this->destination = &(*this->table->getPile(destinationPileNumber));
}


void Pile2PileController::applyMovement() {
	Card card = origin->giveTopCardAway();
	destination->putCardOnTop(card);
}

bool Pile2PileController::isValid() {return true;}
