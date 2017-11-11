/*
 * Pile2FoundationController.h
 *
 *  Created on: Nov 5, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_MOVEMENT_PILE2FOUNDATIONCONTROLLER_H_
#define SRC_CONTROLLER_MOVEMENT_PILE2FOUNDATIONCONTROLLER_H_

#include "Table.h"
#include "OneCardMovementController.h"

class Pile2FoundationController: public OneCardMovementController {
public:
	Pile2FoundationController(Table * t, int origPile, int destFoundation);
	virtual ~Pile2FoundationController(){};
};

#endif /* SRC_CONTROLLER_MOVEMENT_PILE2FOUNDATIONCONTROLLER_H_ */
