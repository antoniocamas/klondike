/*
 * ActionController.h
 *
 *  Created on: Oct 21, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_ACTIONCONTROLLER_H_
#define SRC_CONTROLLER_ACTIONCONTROLLER_H_

#include "Table.h"

class ActionController {
protected:
	Table * table;

public:
	ActionController(Table * table){this->table = table;};
	virtual ~ActionController();

	ActionController(const ActionController& other) = delete;

	virtual bool isValid() = 0;
	virtual void execute() = 0;
};

#endif /* SRC_CONTROLLER_ACTIONCONTROLLER_H_ */
