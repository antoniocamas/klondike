#include <memory>
#include "MovementDescriber.h"
#include "MovementClassifier.h"
#include "MovementClassifierBuilder.h"

MovementDescriber::MovementDescriber():
    originIndex(0), destinatioIndex(0), nextElement(ORIGIN) {
}

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
	if (originCard.isEmpty())
	    nextElement = ORIGINCARD;
	else
	    nextElement = NONE;
    }
}

MovementType MovementDescriber::getType() const {

    MovementClassifierBuilder movementClassifierBuilder = MovementClassifierBuilder();
    shared_ptr<MovementClassifier> classifier =
	movementClassifierBuilder.getMovementClassifer(origin, destination);

    return classifier->getType();
}
