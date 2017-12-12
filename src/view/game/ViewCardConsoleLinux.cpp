#include <memory>
#include "Suit.h"
#include "SuitFlyweightFactory.h"
#include "Card.h"
#include "ViewSuitConsoleLinux.h"
#include "ViewCardConsoleLinux.h"
#include "LinuxTerminalColor.h"
#include "Configurator.h"
#include "StringHandler.h"

string ViewCardConsoleLinux::getRepresentation(Card card) {
    if (!card.isUpTurned() or card.isEmpty())
	return "";

    ViewSuitConsoleLinux viewsuit;
    return viewsuit.getColor(card.getSuitName())+ viewsuit.getNickName(card.getNumber()) +
	viewsuit.getShortName(card.getSuitName()) + RESET ;
}

void ViewCardConsoleLinux::createCardfromRepresentation(string representation) {
    int number = getNumberfromRepresentation(representation);
    this->card = Card(number, getSuitfromRepresentation(representation));
}

int ViewCardConsoleLinux::getNumberfromRepresentation(string representation) {
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

shared_ptr<Suit> ViewCardConsoleLinux::getSuitfromRepresentation(string representation){
    string name = getSuitNamefromRepresentation(representation);
    SuitFlyweightFactory suitFlyweightFactory;
    return suitFlyweightFactory.getSuitIfExists(name);
}

string ViewCardConsoleLinux::getSuitNamefromRepresentation(string representation) const {

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
