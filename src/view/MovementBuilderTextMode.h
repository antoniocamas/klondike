/*
 * MovementBuilderTextMode.h
 *
 *  Created on: Oct 22, 2017
 *      Author: antonio
 */

#ifndef SRC_VIEW_MOVEMENTBUILDERTEXTMODE_H_
#define SRC_VIEW_MOVEMENTBUILDERTEXTMODE_H_

#include <vector>
#include <string>
#include <memory>
#include "Table.h"
#include "MovementController.h"

using namespace std;

class MovementBuilderTextMode {
private:
	Table * table;
	vector<string> userInput;
public:
	MovementBuilderTextMode(Table * t, vector<string> u);
	virtual ~MovementBuilderTextMode();

	shared_ptr<MovementController> getMovement() const;
};

#endif /* SRC_VIEW_MOVEMENTBUILDERTEXTMODE_H_ */
