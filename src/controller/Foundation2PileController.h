/*
 * Foundation2PileController.h
 *
 *  Created on: Nov 5, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_FOUNDATION2PILECONTROLLER_H_
#define SRC_CONTROLLER_FOUNDATION2PILECONTROLLER_H_

#include "MovementController.h"

class Foundation2PileController: public MovementController {
public:
	Foundation2PileController(Table * t, int oriFoundation, int destPile);
	virtual ~Foundation2PileController(){};

	bool isValid();
};

#endif /* SRC_CONTROLLER_FOUNDATION2PILECONTROLLER_H_ */
