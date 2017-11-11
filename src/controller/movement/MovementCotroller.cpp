/*
 * Movement.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#include "Card.h"
#include "MovementController.h"

void MovementController::applyMovement() {
	card::Card card = origin->giveTopCardAway();
	origin->turnTopCard();
	card.upTurn();
	destination->putCardOnTop(card);
}


