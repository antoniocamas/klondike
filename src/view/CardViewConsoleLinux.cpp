/*
 * CardViewConsoleLinux.cpp
 *
 *  Created on: Nov 4, 2017
 *      Author: antonio
 */

#include "Suit.h"
#include "Card.h"
#include "SuitViewConsoleLinux.h"
#include "CardViewConsoleLinux.h"
#include "LinuxTerminalColor.h"
#include "Configurator.h"
#include "StringHandler.h"

string CardViewConsoleLinux::getRepresentation(Card card) {
	SuitViewConsoleLinux suitview;

	return suitview.getColor(card.getSuitName())+ suitview.getNickName(card.getNumber()) +
			suitview.getShortName(card.getSuitName()) + RESET ;
}

void CardViewConsoleLinux::createCardfromRepresentation(string representation) {
	int number = getNumberfromRepresentation(representation);
	Suit suit = getSuitfromRepresentation(representation);
	this->card = Card(number, suit);
}

int CardViewConsoleLinux::getNumberfromRepresentation(string representation) {
	StringHandler stringHandler(representation);
	stringHandler.cutNlastChars(1);
	stringHandler.uppercase();
	string name = stringHandler.getString();

	map<int, string> nicknames = Configurator::getInstance()->getSuitNicknames();
	for (auto it = nicknames.begin(); it != nicknames.end(); ++it)
		if ((*it).second == name)
			return (*it).first;

	return stoi(name);
}

Suit CardViewConsoleLinux::getSuitfromRepresentation(string representation){
	string name = getSuitNamefromRepresentation(representation);
	string color = getSuitColorfromName(name);
	return Suit(name, color, Configurator::getInstance()->getSuitNumberOfCards());
}

string CardViewConsoleLinux::getSuitNamefromRepresentation(string representation) const {

	StringHandler stringHandler(representation);
	stringHandler.keepNlastChars(1);
	stringHandler.uppercase();
	string suitShortName = stringHandler.getString();

	map<string,vector<string>> reprGuide = Configurator::getInstance()->getSuitRepresentationGuide();
	for (auto it = reprGuide.begin(); it != reprGuide.end(); ++it)
		if ((*it).second.at(1) == suitShortName)
			return (*it).first;

	return nullptr;
}

string CardViewConsoleLinux::getSuitColorfromName(string suitName){
	map<string, string> suitModel = Configurator::getInstance()->getSuitModel();
	for (auto it = suitModel.begin(); it != suitModel.end(); ++it)
			if ((*it).first == suitName)
				return (*it).second;
	return nullptr;
}

