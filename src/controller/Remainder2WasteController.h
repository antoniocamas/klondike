/*
 * Remainder2WasteController.h
 *
 *  Created on: Oct 21, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_REMAINDER2WASTECONTROLLER_H_
#define SRC_CONTROLLER_REMAINDER2WASTECONTROLLER_H_

#include "Table.h"
#include "MovementController.h"

class Remainder2WasteController: public MovementController {
public:
	Remainder2WasteController(Table * t);
	virtual ~Remainder2WasteController(){};

	void applyMovement();
	bool isValid();
};

#endif /* SRC_CONTROLLER_REMAINDER2WASTECONTROLLER_H_ */
