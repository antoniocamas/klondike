/*
 * MovementDescriber.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: antonio
 */

#include "MovementDescriber.h"

void MovementDescriber::setOrigin(string origin, int index) {
	this->origin = origin;
	this->originIndex = index;
	transition2NextMovementElement();
}

void MovementDescriber::setDestination(string destination, int index) {
	this->destination = destination;
	this->destinatioIndex = index;
	transition2NextMovementElement();
}

void MovementDescriber::setOriginCard(Card card) {
	this->originCard = card;
	transition2NextMovementElement();
}

void MovementDescriber::transition2NextMovementElement(){
	if (origin.empty())
		nextElement = ORIGIN;
	else if (origin == "remainder")
		nextElement = NONE;
	else if (destination.empty())
		nextElement = DESTINATION;
	else if (origin == "waste" or origin == "foundation" or destination == "foundation")
		nextElement = NONE;
	else if (origin == "pile" and destination == "pile"){
		if (originCard.getNumber() == 0)
			nextElement = ORIGINCARD;
		else
			nextElement = NONE;
	}
}

MovementType MovementDescriber::getType() const {

	MovementType mtype = NOTAMOVEMENT;

	if (origin == "remainder")
		mtype = REMAINDER2WASTE;
	else if (origin == "waste"){
		if (destination == "pile")
			mtype = WASTE2PILE;
		else if (destination == "foundation")
			mtype = WASTE2FOUNDATION;
	}
	else if (origin == "foundation" and destination == "pile")
		mtype = FOUNDATION2PILE;
	else if (origin == "pile"){
		if (destination == "pile")
			mtype = PILE2PILE;
		else if (destination == "foundation")
			mtype = PILE22FOUNDATION;
	}
	return mtype;
}
