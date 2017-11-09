/*
 * Logic.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: antonio
 */

#include <memory>
#include "Logic.h"
#include "Controller.h"
#include "InGameController.h"

using namespace std;

shared_ptr<Controller> Logic::getController() {
	shared_ptr<Controller> controller;

	switch(state){
	case START:
		state = INGAME;
		break;
	case INGAME:
		controller = make_shared<InGameController>(&table, view);
		break;
	case FINISH:
		state = EXIT;
		break;
	default:
		break;

	}

	return controller;
}
