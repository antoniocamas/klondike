/*
 * Movement.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#include "Movement.h"

Movement::Movement(string stackOrigin, int originIndex, string stackDestination,
		int destinationIndex, Card cardOrigin) {
	this->stackOrigin = stackOrigin;
	this->originIndex = originIndex;
	this->stackDestination = stackDestination;
	this->destinationIndex = destinationIndex;
	this->cardOrigin = cardOrigin;
}

Movement::~Movement() {
	// TODO Auto-generated destructor stub
}


