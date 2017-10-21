/*
 * Movement.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#include "MovementController.h"
#include "Table.h"
#include "Card.h"

//Movement::Movement(Tableau table) {
//	this->table &table;
//}

MovementController::~MovementController() {
	// TODO Auto-generated destructor stub
}

void MovementController::applyMovement() {
	Card card = origin->giveTopCardAway();
	card.upTurn();
	destination->putCardOnTop(card);
}


