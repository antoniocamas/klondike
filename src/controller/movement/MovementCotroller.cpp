/*
 * Movement.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#include "Table.h"
#include "Card.h"
#include "movement/MovementController.h"

void MovementController::applyMovement() {
	Card card = origin->giveTopCardAway();
	origin->turnTopCard();
	card.upTurn();
	destination->putCardOnTop(card);
}


