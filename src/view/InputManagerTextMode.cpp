/*
 * MovementBuilderTextMode.cpp
 *
 *  Created on: Oct 21, 2017
 *      Author: antonio
 */

#include "InputManagerTextMode.h"

#include <vector>
#include <string>
#include <memory>
#include <regex>

#include "MovementController.h"
#include "Remainder2WasteController.h"

using namespace std;

InputManagerTextMode::InputManagerTextMode(Table* table,
		std::map<string, string>& tableElementRepresenter) {

	this->remainder = tableElementRepresenter["remainder"];
	this->waste = tableElementRepresenter["waste"];
	this->foundation = tableElementRepresenter["foundation"] + "[1-" + to_string(
			table->getNumberOfFundations()) + "]";
	this->pile = tableElementRepresenter["pile"] + "[1-" + to_string(
			table->getNumberOfPiles()) + "]";

	//regex is something like "r|w|f[1-4]|p[1-7]]|card ..."
	this->validCommandsRegex  = this->remainder + "|" + this->waste + "|"
			+ this->foundation + "|" + this->pile;

}

InputManagerTextMode::~InputManagerTextMode() {
	// TODO Auto-generated destructor stub
}

string InputManagerTextMode::getNextExpectedElement() const {
	string nextElement;
	size_t numberOfCommands = this->dataFromUser.size();

	if (this->dataFromUser.empty())
		nextElement = "Origin";
	else if (isWasteOrFoundationTheOrigin())
		nextElement = "Destination";
	else if (isPileTheOrigin()){
		if (numberOfCommands == 1)
			nextElement = "Destination";
		else if (numberOfCommands == 2)
			nextElement = "Origin card";
	}
	return nextElement;
}

bool InputManagerTextMode::isEnoughInput() {

	if (this->dataFromUser.empty())
		return false;

	bool enoughData = false;
	size_t numberOfCommands = this->dataFromUser.size();

	if (isRemaninderTheOrigin())
		enoughData = true;
	else if  (numberOfCommands < 2)
		enoughData = false;
	else if (isWasteOrFoundationTheOrigin())
		enoughData = true;
	else if (isPileTheOrigin()){
		if (isFoundationTheDestination())
			enoughData = true;
		else if (numberOfCommands > 2)
			enoughData = true;
	}

	return enoughData;
}

bool InputManagerTextMode::isInputCorrect(string data) const {

	bool correct = false;
	size_t numberOfCommands = this->dataFromUser.size();

	if (numberOfCommands < 2){
		if(regex_match(data, this->validCommandsRegex))
			correct = true;
	}
	else if (numberOfCommands == 2)
		correct = true;

	return correct;
}

void InputManagerTextMode::addNewInput(string data) {
	this->dataFromUser.push_back(data);
}

string InputManagerTextMode::getOrigin() const {
	return this->dataFromUser.front();
}

bool InputManagerTextMode::isRemaninderTheOrigin() const {
	return regex_match(this->getOrigin(), regex{this->remainder});
}

bool InputManagerTextMode::isWasteOrFoundationTheOrigin() const {
	return regex_match(this->getOrigin(), regex{this->waste + "|" + this->foundation});
}

bool InputManagerTextMode::isPileTheOrigin() const {
	return regex_match(this->getOrigin(), regex{this->pile});
}

bool InputManagerTextMode::isFoundationTheDestination() const {
	return regex_match(this->dataFromUser.at(1), regex{this->foundation});
}
