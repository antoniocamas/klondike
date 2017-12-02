
#include <memory>
#include "Suit.h"
#include "SuitFlyweightFactory.h"
#include "Card.h"
#include "SuitViewConsoleLinux.h"
#include "CardViewConsoleLinux.h"
#include "LinuxTerminalColor.h"
#include "Configurator.h"
#include "StringHandler.h"

string CardViewConsoleLinux::getRepresentation(Card card) {
	if (!card.isUpTurned() or card.isEmpty())
		return "";

	SuitViewConsoleLinux suitview;
	return suitview.getColor(card.getSuitName())+ suitview.getNickName(card.getNumber()) +
			suitview.getShortName(card.getSuitName()) + RESET ;
}

void CardViewConsoleLinux::createCardfromRepresentation(string representation) {
	int number = getNumberfromRepresentation(representation);
	this->card = Card(number, getSuitfromRepresentation(representation));
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

	int number = 0;
	try {
	    number = stoi(name);
	}
	catch (const std::invalid_argument& ia) {}
	return number;
}

shared_ptr<Suit> CardViewConsoleLinux::getSuitfromRepresentation(string representation){
	string name = getSuitNamefromRepresentation(representation);
	if (name == "")
		return nullptr;
	string color = getSuitColorfromName(name);
	SuitFlyweightFactory suitFlyweightFactory;
	return suitFlyweightFactory.getSuit(name, color, Configurator::getInstance()->getSuitNumberOfCards());
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

	return "";
}

string CardViewConsoleLinux::getSuitColorfromName(string suitName){
	map<string, string> suitModel = Configurator::getInstance()->getSuitModel();
	for (auto it = suitModel.begin(); it != suitModel.end(); ++it)
			if ((*it).first == suitName)
				return (*it).second;
	return nullptr;
}
