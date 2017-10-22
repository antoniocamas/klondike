/*
 * MovementBuilderTextMode.h
 *
 *  Created on: Oct 21, 2017
 *      Author: antonio
 */

#ifndef SRC_VIEW_INPUTMANAGERTEXTMODE_H_
#define SRC_VIEW_INPUTMANAGERTEXTMODE_H_

#include <vector>
#include <string>
#include <memory>
#include <regex>
#include <map>
#include "Table.h"

using namespace std;

class InputManagerTextMode {
	string remainder;
	string waste;
	string foundation;
	string pile;
	regex validCommandsRegex;
	Table * table;
	vector<string> dataFromUser;

public:
	InputManagerTextMode(Table* table);
	InputManagerTextMode(Table* t, std::map<string, string>& r);
	virtual ~InputManagerTextMode();

	bool isInputCorrect(string data)const;
	bool isEnoughInput();
	void addNewInput(string data);
	vector<string> getUserData(){return this->dataFromUser;}
};

#endif /* SRC_VIEW_INPUTMANAGERTEXTMODE_H_ */
