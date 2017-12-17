
#include <memory>
#include "InGameController.h"
#include "MovementControllerCreator.h"
#include "MovementType.h"

InGameController::InGameController(
    std::shared_ptr<Table> t, std::shared_ptr<View> v, State& s,
    std::shared_ptr<TableRegistry> tr):
    Controller(t, v), state(s), tableRegistry(tr) {
};

void InGameController::control() {
    view->accept(this);
}

void InGameController::visit(MovementDescriber movementDescriber) {
    movement = movementDescriber;
    if (movement.getType() == MovementType::NOTAMOVEMENT)
	state = State::MENU;
    else
	move();
}

void InGameController::move() {
    MovementControllerCreator movementControllerCreator(table.get(), movement);
    shared_ptr<MovementController> movementController = movementControllerCreator.getMovement();

    if(movementController->isValid()) {
    	movementController->applyMovement();
	tableRegistry->updateHistory(table.get());
    }

    if (table->areAllFoundationsComplete()){
    	state = State::FINISH;
    }
}
