/*
 * Pile2FoundationController.h
 *
 *  Created on: Nov 5, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_MOVEMENT_PILE2FOUNDATIONCONTROLLER_H_
#define SRC_CONTROLLER_MOVEMENT_PILE2FOUNDATIONCONTROLLER_H_

#include "movement/MovementController.h"

class Pile2FoundationController: public MovementController {
public:
	Pile2FoundationController(Table * t, int origPile, int destFoundation);
	virtual ~Pile2FoundationController(){};

	bool isValid();
};

#endif /* SRC_CONTROLLER_MOVEMENT_PILE2FOUNDATIONCONTROLLER_H_ */
