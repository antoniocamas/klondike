/*
 * MovementBuilderTextMode.h
 *
 *  Created on: Oct 21, 2017
 *      Author: antonio
 */

#ifndef SRC_VIEW_MOVEMENTBUILDERTEXTMODE_H_
#define SRC_VIEW_MOVEMENTBUILDERTEXTMODE_H_

#include <vector>
#include <string>
#include <memory>
#include <regex>
#include "MovementController.h"
#include "Table.h"

class MovementBuilderTextMode {
	string remainder;
	string waste;
	string foundation;
	string pile;
	std::regex validCommandsRegex;
	Table * table;
	vector<string> dataFromUser;

public:
	MovementBuilderTextMode(Table* table);
	virtual ~MovementBuilderTextMode();

	bool isInputCorrect(string data)const;
	bool isEnoughInput();
	void addNewInput(string data);
	shared_ptr<MovementController> getMovement() const;
};

#endif /* SRC_VIEW_MOVEMENTBUILDERTEXTMODE_H_ */
