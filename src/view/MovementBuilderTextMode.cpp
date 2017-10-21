/*
 * MovementBuilderTextMode.cpp
 *
 *  Created on: Oct 21, 2017
 *      Author: antonio
 */

#include <vector>
#include <string>
#include <memory>
#include <regex>

#include "MovementController.h"
#include "Remainder2WasteController.h"
#include "MovementBuilderTextMode.h"

using namespace std;

MovementBuilderTextMode::MovementBuilderTextMode(Table * table) {
	this->table = table;
	this->remainder = "r";
	this->waste = "w";
	this->foundation = "f[1-" + to_string(this->table->getNumberOfFundations()) + "]";
	this->pile = "p[1-" + to_string(this->table->getNumberOfPiles()) + "]";

	//regex is something like "r|w|f[1-4]|p[1-7]]|card ..."
	this->validCommandsRegex  = this->remainder + "|" + this->waste + "|"
			+ this->foundation + "|" + this->pile + "|card ...";
}

MovementBuilderTextMode::~MovementBuilderTextMode() {
	// TODO Auto-generated destructor stub
}

bool MovementBuilderTextMode::isEnoughInput() {
	if (this->dataFromUser.empty())
		return false;

//	regex reg = this->remainder;
//	if (regex_match(this->dataFromUser.front(),  reg))
//		return true;
//	if (regex_match((regex)this->dataFromUser.front(), this->pile) and this->dataFromUser.size()> 2)
//		return true;

	return false;
}

bool MovementBuilderTextMode::isInputCorrect(string data) const {
//	std::list<char>::const_iterator foundIt = std::find(
//			validCommands.begin(), validCommands.end(), data[0]);
//
//	bool found = false;
//
//	if (findIter != validCommands.end()){
//		found = true;
//	}
//
//	if (found and )
//
//	return found;

	if(regex_match(data, this->validCommandsRegex))
		return true;
	return false;

}

void MovementBuilderTextMode::addNewInput(string data) {
	this->dataFromUser.push_back(data);
}

shared_ptr<MovementController> MovementBuilderTextMode::getMovement() const{
	shared_ptr<MovementController> movement(new Remainder2WasteController(this->table));
	return movement;
}
