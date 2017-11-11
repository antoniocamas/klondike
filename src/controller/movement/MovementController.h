/*
 * Movement.h
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#ifndef SRC_MOVEMENT_H_
#define SRC_MOVEMENT_H_

#include "CardStack.h"

class MovementController {

protected:
	card::CardStack* origin;
	card::CardStack* destination;

public:
	MovementController(){};
	virtual ~MovementController(){};

	virtual bool isValid() = 0;
	virtual void applyMovement();
};

#endif /* SRC_MOVEMENT_H_ */
