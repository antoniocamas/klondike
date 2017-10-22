/*
 * MovementBuilderTextMode.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: antonio
 */

#include <vector>
#include <string>
#include <memory>
#include <regex>
#include "MovementController.h"
#include "Remainder2WasteController.h"
#include "Waste2PileController.h"
#include "MovementBuilderTextMode.h"

//debug
#include <iostream>

using namespace std;

MovementBuilderTextMode::MovementBuilderTextMode(Table * table,
		vector<string> userInput, map<string, string> inputDictionary) {
	this->table = table;
	this->userInput = userInput;
	this->inputDictionary = inputDictionary;
}

MovementBuilderTextMode::~MovementBuilderTextMode() {
	// TODO Auto-generated destructor stub
}

shared_ptr<MovementController> MovementBuilderTextMode::getMovement() const{
	vector<vector<string>> classifiers = this->translateInput();
	shared_ptr<MovementController> movement = NULL;


	vector<string> origin = classifiers.front();
	if (origin.front() == "remainder")
		return (shared_ptr<MovementController>) new Remainder2WasteController(this->table);

	vector<string> destination = classifiers.at(1);
	if (origin.front() == "waste"){
		if(destination.front() == "pile")
			return (shared_ptr<MovementController>) new Waste2PileController(
					this->table, stoi(destination.back())-1);
	}

//	if(classifiers.at(0) == "remainder"){
//		shared_ptr<MovementController> movement(new Remainder2WasteController(this->table));
//		return movement;
//	}
	//retrievecardifneeded
	//createmovement
	//returnit


	return movement;
}

vector<vector<string>> MovementBuilderTextMode::translateInput() const {
	std::smatch matches;
	vector<vector<string>> classifiers;
	for (auto iti = this->userInput.begin(); iti != this->userInput.end(); ++iti) {
		for (auto itj = this->inputDictionary.begin(); itj != this->inputDictionary.end(); ++itj){
			if (regex_match((*iti), matches, regex{"(" + (*itj).second + ")(.*)"})){
				vector<string> element;
				element.push_back((*itj).first);
				for(unsigned int i = 1; i < matches.size(); ++i){
					if (matches[i] != "")
						element.push_back(matches[i]);
				}
				classifiers.push_back(element);
			}
		}
	}

//	for (auto it = classifiers.begin(); it != classifiers.end(); ++it) {
//		cout << "Element: ";
//		for(unsigned int i = 0; i < (*it).size(); ++i){
//			cout << " " << (*it)[i];
//		}
//
//	}

	return classifiers;
}
