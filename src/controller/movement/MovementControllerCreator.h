/*
 * MovementBuilderTextMode.h
 *
 *  Created on: Oct 22, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_MOVEMENT_MOVEMENTCONTROLLERCREATOR_H_
#define SRC_CONTROLLER_MOVEMENT_MOVEMENTCONTROLLERCREATOR_H_

#include <memory>
#include <map>

#include "movement/MovementController.h"
#include "Table.h"
#include "MovementDescriber.h"

using namespace std;

class MovementControllerCreator {
private:
	Table * table;
	MovementDescriber movementDescriber;

public:
	MovementControllerCreator(Table * t, MovementDescriber m): table(t), movementDescriber(m){};
	virtual ~MovementControllerCreator(){};

	shared_ptr<MovementController> getMovement() const;

private:

};

#endif /* SRC_CONTROLLER_MOVEMENT_MOVEMENTCONTROLLERCREATOR_H_ */
