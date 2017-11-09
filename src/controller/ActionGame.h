/*
 * ActionGame.h
 *
 *  Created on: Oct 21, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_ACTIONGAME_H_
#define SRC_CONTROLLER_ACTIONGAME_H_

#include <memory>
#include "Table.h"
#include "ActionController.h"
#include "MovementController.h"

class ActionGame: public ActionController {

	shared_ptr<MovementController> movement;

public:
	ActionGame(Table * t, shared_ptr<MovementController> m);
	virtual ~ActionGame(){};

	bool isValid();
	void execute();
};

#endif /* SRC_CONTROLLER_ACTIONGAME_H_ */
