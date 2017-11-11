/*
 * OneCardMovementController.h
 *
 *  Created on: Nov 11, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_MOVEMENT_ONECARDMOVEMENTCONTROLLER_H_
#define SRC_CONTROLLER_MOVEMENT_ONECARDMOVEMENTCONTROLLER_H_

#include "MovementController.h"

class OneCardMovementController: public MovementController {
public:
	OneCardMovementController(){};
	virtual ~OneCardMovementController(){};

	virtual bool isValid();
};

#endif /* SRC_CONTROLLER_MOVEMENT_ONECARDMOVEMENTCONTROLLER_H_ */
