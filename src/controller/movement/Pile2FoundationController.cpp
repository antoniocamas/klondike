/*
 * Pile2FoundationController.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: antonio
 */

#include "Pile2FoundationController.h"

Pile2FoundationController::Pile2FoundationController(Table * table,
		int originPileNumber, int destinationFoundationNumber) {

	this->origin = &(*table->getPile(originPileNumber));
	this->destination = &(*table->getFoundation(destinationFoundationNumber));
}
