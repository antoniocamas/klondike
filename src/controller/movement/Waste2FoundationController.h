/*
 * Waste2FoundationController.h
 *
 *  Created on: Nov 5, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_MOVEMENT_WASTE2FOUNDATIONCONTROLLER_H_
#define SRC_CONTROLLER_MOVEMENT_WASTE2FOUNDATIONCONTROLLER_H_

#include "movement/MovementController.h"

class Waste2FoundationController: public MovementController {
public:
	Waste2FoundationController(Table * t, int foundationNumber);
	virtual ~Waste2FoundationController(){};

	bool isValid();
};

#endif /* SRC_CONTROLLER_MOVEMENT_WASTE2FOUNDATIONCONTROLLER_H_ */
