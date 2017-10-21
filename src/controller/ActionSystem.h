/*
 * ActionSystem.h
 *
 *  Created on: Oct 21, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_ACTIONSYSTEM_H_
#define SRC_CONTROLLER_ACTIONSYSTEM_H_

#include "ActionController.h"

class ActionSystem: public ActionController {
public:
	ActionSystem(Table * t): ActionController(t) {};
	virtual ~ActionSystem();

	void execute();
};

#endif /* SRC_CONTROLLER_ACTIONSYSTEM_H_ */
