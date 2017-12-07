#include <vector>
#include <string>
#include <memory>
#include <regex>
#include "InputManagerTextMode.h"
#include "MovementDescriber.h"
#include "CardViewConsoleLinux.h"

using namespace std;

InputManagerTextMode::InputManagerTextMode(
    Table* table, std::map<string, string>& inputDictionary):inputDictionary(inputDictionary) {

    string remainder = inputDictionary["remainder"];
    string waste = inputDictionary["waste"];
    string foundation = inputDictionary["foundation"] + "[1-" + to_string(
	table->getNumberOfFundations()) + "]";
    string pile = inputDictionary["pile"] + "[1-" + to_string(
	table->getNumberOfPiles()) + "]";
    string menu = inputDictionary["menu"] ;

    //regex is something like "r|w|f[1-4]|p[1-7]|m"
    this->validCommandsRegex = remainder + "|" + waste + "|" +
	foundation + "|" + pile + "|" + menu;
}

string InputManagerTextMode::getNextExpectedElement() const {
    string nextElement;
    switch(movement.getNextExpectedElement()){
    case ORIGIN:
	nextElement = "Origin";
	break;
    case DESTINATION:
	nextElement = "Destination";
	break;
    case ORIGINCARD:
	nextElement = "Origin card";
	break;
    default:
	break;
    }
    return nextElement;
}

bool InputManagerTextMode::isEnoughInput()  {
    return movement.getNextExpectedElement() == NONE;
}

bool InputManagerTextMode::isInputCorrect(string data) const {

    bool correct = false;

    if (movement.getNextExpectedElement() == ORIGINCARD){
	CardViewConsoleLinux cardChecker;
	cardChecker.createCardfromRepresentation(data);
	correct = cardChecker.isCardCreated();
    }
    else{
	if(regex_match(data, this->validCommandsRegex))
	    correct = true;
    }

    return correct;
}

void InputManagerTextMode::addNewInput(string data) {
    switch(movement.getNextExpectedElement()){
    case ORIGIN:
	setOrigin(data);
	break;
    case DESTINATION:
	setDestination(data);
	break;
    case ORIGINCARD:
	setOriginCard(data);
	break;
    default:
	break;
    }
}

void InputManagerTextMode::setOriginCard(string data) {
    movement.setOriginCard(translateInput2Card(data));
}

void InputManagerTextMode::setOrigin(string data) {
    string stack;
    unsigned int index;
    translateInput2Stack(data, stack, index);
    movement.setOrigin(stack, index-1);
}

void InputManagerTextMode::setDestination(string data) {
    string stack;
    unsigned int index;
    translateInput2Stack(data, stack, index);
    movement.setDestination(stack, index-1);
}

void InputManagerTextMode::translateInput2Stack(string input, string &stack, unsigned int &index){
    std::smatch matches;
    index = 0;
    for (auto itj = this->inputDictionary.begin(); itj != this->inputDictionary.end(); ++itj){
	if (regex_match(input, matches, regex{"(" + (*itj).second + ")(.*)"})){
	    stack = (*itj).first;
	    for(unsigned int i = 2; i < matches.size(); ++i){
		if (matches[i] != "")
		    index = stoi(matches[i]);
	    }
	}
    }
}

card::Card InputManagerTextMode::translateInput2Card(string input){
    CardViewConsoleLinux cardCreator;
    cardCreator.createCardfromRepresentation(input);
    return cardCreator.getCard();
}
