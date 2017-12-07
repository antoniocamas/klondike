
#include <memory>
#include "InGameController.h"
#include "MovementControllerCreator.h"

void InGameController::control() {
    view->accept(this);
}

void InGameController::visit(MovementDescriber movementDescriber) {
    movement = movementDescriber;
    if (movement.getType() == NOTAMOVEMENT)
	state = State::MENU;
    else
	move();
}

void InGameController::move() {
    MovementControllerCreator movementControllerCreator(table, movement);
    shared_ptr<MovementController> movementController = movementControllerCreator.getMovement();

    if(movementController->isValid())
    	movementController->applyMovement();

    if (table->areAllFoundationsComplete()){
//    	view->showWinMessage();
    	state = State::FINISH;
    }
}
