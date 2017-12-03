
#include <memory>
#include "InGameController.h"
#include "MovementControllerCreator.h"

void InGameController::control() {
    view->showTable();

    MovementControllerCreator movementControllerCreator(this->table, view->getNextMovement());
    shared_ptr<MovementController> movementController = movementControllerCreator.getMovement();

    if(movementController->isValid())
	movementController->applyMovement();

    if (table->areAllFoundationsComplete()){
	view->showWinMessage();
	state = State::FINISH;
    }
}
