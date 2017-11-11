/*
 * Waste2PileController.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: antonio
 */

#include "Waste2PileController.h"

//#include "Card.h"
//#include "Pile.h"

Waste2PileController::Waste2PileController(Table * table, int pileNumber){
	this->destination = &(*table->getPile(pileNumber));
	this->origin = table->getWaste();
};
