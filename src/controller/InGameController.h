/*
 * InGameController.h
 *
 *  Created on: Nov 9, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_INGAMECONTROLLER_H_
#define SRC_CONTROLLER_INGAMECONTROLLER_H_

#include "State.h"
#include "Controller.h"

class InGameController: public Controller {
private:
	State& state;
public:
	InGameController(Table * t, std::shared_ptr<View> v, State& s): Controller(t, v),state(s){};
	virtual ~InGameController(){};
	void control();
};

#endif /* SRC_CONTROLLER_INGAMECONTROLLER_H_ */
