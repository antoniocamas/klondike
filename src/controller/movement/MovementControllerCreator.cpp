#include <memory>
#include "MovementControllerCreator.h"
#include "Foundation2PileController.h"
#include "MovementController.h"
#include "Pile2FoundationController.h"
#include "Pile2PileController.h"
#include "Remainder2WasteController.h"
#include "Waste2FoundationController.h"
#include "Waste2PileController.h"

using namespace std;

shared_ptr<MovementController> MovementControllerCreator::getMovement() const{
    shared_ptr<MovementController> movement = nullptr;

    switch(movementDescriber.getType()){
    case REMAINDER2WASTE:
	movement = make_shared<Remainder2WasteController>(this->table);
	break;
    case WASTE2PILE:
	movement = make_shared<Waste2PileController>(
	    this->table, movementDescriber.getDestinationIndex());
	break;
    case WASTE2FOUNDATION:
	movement = make_shared<Waste2FoundationController>(
	    this->table, movementDescriber.getDestinationIndex());
	break;
    case FOUNDATION2PILE:
	movement = make_shared<Foundation2PileController>(
	    this->table, movementDescriber.getOriginIndex(),
	    movementDescriber.getDestinationIndex());
	break;
    case PILE22FOUNDATION:
	movement = make_shared<Pile2FoundationController>(
	    this->table, movementDescriber.getOriginIndex(),
	    movementDescriber.getDestinationIndex());
	break;
    case PILE2PILE:
	movement = make_shared<Pile2PileController>(
	    this->table, movementDescriber.getOriginIndex(),
	    movementDescriber.getDestinationIndex(),
	    movementDescriber.getOriginCard());
	break;
    case NOTSUPPORTED:
	break;
    }

    return movement;
}

