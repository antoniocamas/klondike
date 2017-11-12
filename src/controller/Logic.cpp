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
	case State::START:
		state = State::INGAME;
		break;
	case State::INGAME:
		controller = make_shared<InGameController>(&table, view, state);
		break;
	case State::FINISH:
		state = State::EXIT;
		break;
	default:
		break;

	}

	return controller;
}
