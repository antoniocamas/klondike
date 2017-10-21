/*
 * Movement.h
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#ifndef SRC_MOVEMENT_H_
#define SRC_MOVEMENT_H_

#include "Table.h"
#include "CardStack.h"

class MovementController {

protected:
	Table * table;
	CardStack* origin;
	CardStack* destination;

public:
	MovementController(Table* table){this->table = table;}
	virtual ~MovementController();

	virtual bool isValid() = 0;
	virtual void applyMovement();
};

#endif /* SRC_MOVEMENT_H_ */
