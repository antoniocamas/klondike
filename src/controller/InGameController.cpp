/*
 * InGameController.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: antonio
 */

#include "InGameController.h"
#include "ActionController.h"

void InGameController::control() {
	view->showTable();
	shared_ptr<ActionController> action;
	action = view->getAction();
	if (action->isValid())
		action->execute();
}
