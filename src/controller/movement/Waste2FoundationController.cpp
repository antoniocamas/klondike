/*
 * Waste2FoundationController.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: antonio
 */

#include "Waste2FoundationController.h"

Waste2FoundationController::Waste2FoundationController(Table * table, int foundationNumber){
	this->destination = &(*table->getFoundation(foundationNumber));
	this->origin = table->getWaste();
}
