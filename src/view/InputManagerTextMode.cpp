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

InputManagerTextMode::InputManagerTextMode(Table * table) {
	this->table = table;
	this->remainder = "r";
	this->waste = "w";
	this->foundation = "f[1-" + to_string(this->table->getNumberOfFundations()) + "]";
	this->pile = "p[1-" + to_string(this->table->getNumberOfPiles()) + "]";

	//regex is something like "r|w|f[1-4]|p[1-7]]|card ..."
	this->validCommandsRegex  = this->remainder + "|" + this->waste + "|"
			+ this->foundation + "|" + this->pile + "|card ...";
}

InputManagerTextMode::InputManagerTextMode(Table* t,
		std::map<string, string>& tableElementRepresenter) {
	this->table = table;
	this->remainder = tableElementRepresenter["remainder"];
	this->waste = tableElementRepresenter["waste"];
	this->foundation = tableElementRepresenter["foundation"] + "[1-" + to_string(
			this->table->getNumberOfFundations()) + "]";
	this->pile = tableElementRepresenter["pile"] + "[1-" + to_string(
			this->table->getNumberOfPiles()) + "]";

	//regex is something like "r|w|f[1-4]|p[1-7]]|card ..."
	this->validCommandsRegex  = this->remainder + "|" + this->waste + "|"
			+ this->foundation + "|" + this->pile + "|card ...";

}

InputManagerTextMode::~InputManagerTextMode() {
	// TODO Auto-generated destructor stub
}

bool InputManagerTextMode::isEnoughInput() {

	if (this->dataFromUser.empty())
		return false;

	string origin = this->dataFromUser.front();
	size_t numberOfCommands = this->dataFromUser.size();

	if (regex_match(origin, regex{this->remainder}))
		return true;
	if (numberOfCommands < 2)
		return false;
	if (regex_match(origin, regex{this->waste + "|" + this->foundation}))
		return true;
	if (regex_match(origin, regex{this->pile})){
		if (regex_match(this->dataFromUser.at(1), regex{this->foundation}))
			return true;
		if (numberOfCommands > 2)
			return true;
	}

	return false;
}

bool InputManagerTextMode::isInputCorrect(string data) const {
	if(regex_match(data, this->validCommandsRegex))
		return true;
	return false;
}

void InputManagerTextMode::addNewInput(string data) {
	this->dataFromUser.push_back(data);
}
