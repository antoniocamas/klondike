/*
 * OneCardMovementController.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: antonio
 */

#include "Card.h"
#include "OneCardMovementController.h"

bool OneCardMovementController::isValid(){
	if (this->origin->isEmpty())
		return false;
	const card::Card * card = this->origin->showTopCard();
	return this->destination->isPuttingDownPossible(*card);
}
