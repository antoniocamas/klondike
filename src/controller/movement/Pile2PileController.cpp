/*
 * Pile2PileController.cpp
 *
 *  Created on: Nov 4, 2017
 *      Author: antonio
 */

#include "movement/Pile2PileController.h"

#include <vector>

Pile2PileController::Pile2PileController(Table * t, int originPileNumber, int destinationPileNumber,
		Card originCard): MovementController(t), originCard(originCard) {

	this->origin = &(*this->table->getPile(originPileNumber));
	this->destination = &(*this->table->getPile(destinationPileNumber));
}


void Pile2PileController::applyMovement() {
	vector<Card> cards = origin->giveTopCardAway(origin->numberOfCardsOnTopOf(originCard));
	origin->turnTopCard();
	destination->putCardOnTop(cards);
}

bool Pile2PileController::isValid() {

	if (origin->isMovingTopStackPossible(originCard) and
			destination->isPuttingDownPossible(originCard))
		return true;
	return false;
}
