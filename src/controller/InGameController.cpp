/*
 * InGameController.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: antonio
 */


#include <memory>
#include "InGameController.h"
#include "ActionController.h"
#include "MovementControllerCreator.h"

void InGameController::control() {
	view->showTable();
	shared_ptr<ActionController> action;

	MovementControllerCreator movementControllerCreator(this->table, view->getNextMovement());
	shared_ptr<MovementController> movementController = movementControllerCreator.getMovement();

	if(movementController->isValid())
		movementController->applyMovement();
//	action = view->getAction();
//	if (action->isValid())
//		action->execute();
}
