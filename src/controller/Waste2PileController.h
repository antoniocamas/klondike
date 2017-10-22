/*
 * Waste2PileController.h
 *
 *  Created on: Oct 22, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_WASTE2PILECONTROLLER_H_
#define SRC_CONTROLLER_WASTE2PILECONTROLLER_H_

#include "MovementController.h"

class Waste2PileController: public MovementController {
public:
	Waste2PileController(Table * t, int p);
	virtual ~Waste2PileController();

	bool isValid();
};

#endif /* SRC_CONTROLLER_WASTE2PILECONTROLLER_H_ */
