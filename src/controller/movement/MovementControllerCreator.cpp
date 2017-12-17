#include <memory>
#include "MovementType.h"
#include "MovementControllerCreator.h"
#include "Foundation2PileController.h"
#include "MovementController.h"
#include "Pile2FoundationController.h"
#include "Pile2PileController.h"
#include "Remainder2WasteController.h"
#include "Waste2FoundationController.h"
#include "Waste2PileController.h"

using namespace std;

MovementControllerCreator::MovementControllerCreator
(Table* t, MovementDescriber m): table(t), movementDescriber(m) {
};

shared_ptr<MovementController> MovementControllerCreator::getMovement() const{
    shared_ptr<MovementController> movement = nullptr;

    switch(movementDescriber.getType()){
    case MovementType::REMAINDER2WASTE:
	movement = make_shared<Remainder2WasteController>(this->table);
	break;
    case MovementType::WASTE2PILE:
	movement = make_shared<Waste2PileController>(
	    this->table, movementDescriber.getDestinationIndex());
	break;
    case MovementType::WASTE2FOUNDATION:
	movement = make_shared<Waste2FoundationController>(
	    this->table, movementDescriber.getDestinationIndex());
	break;
    case MovementType::FOUNDATION2PILE:
	movement = make_shared<Foundation2PileController>(
	    this->table, movementDescriber.getOriginIndex(),
	    movementDescriber.getDestinationIndex());
	break;
    case MovementType::PILE22FOUNDATION:
	movement = make_shared<Pile2FoundationController>(
	    this->table, movementDescriber.getOriginIndex(),
	    movementDescriber.getDestinationIndex());
	break;
    case MovementType::PILE2PILE:
	movement = make_shared<Pile2PileController>(
	    this->table, movementDescriber.getOriginIndex(),
	    movementDescriber.getDestinationIndex(),
	    movementDescriber.getOriginCard());
	break;
    case MovementType::NOTAMOVEMENT:
	break;
    }

    return movement;
}

