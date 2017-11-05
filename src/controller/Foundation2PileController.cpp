/*
 * Foundation2PileController.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: antonio
 */

#include "Foundation2PileController.h"

Foundation2PileController::Foundation2PileController(Table * t,
		int originFoundationNumber, int destinationPileNumber): MovementController(t){
	this->origin = &(*this->table->getFoundation(originFoundationNumber));
	this->destination = &(*this->table->getPile(destinationPileNumber));
}

bool Foundation2PileController::isValid(){

#include <iostream>
	using namespace std;
	cout << "Foundation2PileController" << endl;
	if (this->origin->isEmpty())
		return false;
	const card::Card * card = this->origin->showTopCard();
	return this->destination->isPuttingDownPossible(*card);

}
