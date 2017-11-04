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
	//Table * table;
	vector<string> dataFromUser;

public:
	InputManagerTextMode(Table* t, std::map<string, string>& r);
	virtual ~InputManagerTextMode();

	bool isInputCorrect(string data)const;
	bool isEnoughInput();
	void addNewInput(string data);
	string getNextExpectedElement() const;
	vector<string> getUserData(){return this->dataFromUser;}

private:
	string getOrigin() const;
	bool isRemaninderTheOrigin() const;
	bool isWasteOrFoundationTheOrigin() const;
	bool isPileTheOrigin() const;
	bool isFoundationTheDestination() const;

};

#endif /* SRC_VIEW_INPUTMANAGERTEXTMODE_H_ */
