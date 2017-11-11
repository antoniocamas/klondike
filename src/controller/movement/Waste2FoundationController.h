/*
 * Waste2FoundationController.h
 *
 *  Created on: Nov 5, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_MOVEMENT_WASTE2FOUNDATIONCONTROLLER_H_
#define SRC_CONTROLLER_MOVEMENT_WASTE2FOUNDATIONCONTROLLER_H_

#include "Table.h"
#include "OneCardMovementController.h"

class Waste2FoundationController: public OneCardMovementController {
public:
	Waste2FoundationController(Table * t, int foundationNumber);
	virtual ~Waste2FoundationController(){};
};

#endif /* SRC_CONTROLLER_MOVEMENT_WASTE2FOUNDATIONCONTROLLER_H_ */
