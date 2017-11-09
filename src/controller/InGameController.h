/*
 * InGameController.h
 *
 *  Created on: Nov 9, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_INGAMECONTROLLER_H_
#define SRC_CONTROLLER_INGAMECONTROLLER_H_

#include "Controller.h"

class InGameController: public Controller {
public:
	InGameController(Table * t, std::shared_ptr<View> v):Controller(t, v){};
	virtual ~InGameController(){};
	void control();
};

#endif /* SRC_CONTROLLER_INGAMECONTROLLER_H_ */
