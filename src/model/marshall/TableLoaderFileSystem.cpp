#include <regex>
#include <memory>
#include "TableLoaderFileSystem.h"
#include "SuitFlyweightFactory.h"
#include "FileSystemTools.h"
#include "Configurator.h"

using namespace std;

TableLoaderFileSystem::TableLoaderFileSystem():
    TableLoaderImplementor(), delimiters({":", " ", ",", "\n"}) {
    directory = Configurator::getInstance()->getSavingsDirectory();
    extension = ".sav";
};

TableLoaderFileSystem::~TableLoaderFileSystem() {
}

vector<string> TableLoaderFileSystem::getSavedGames() {
    vector<string> savedGames;
    FileSystemTools fileSystemTool;
    regex pattern("(.*)(" + extension +")");
    smatch matches;
    for (string item : fileSystemTool.listElementsInDir(directory)) {
	if(regex_match(item, matches, pattern)){
	    savedGames.push_back(matches[1]);
	}
    }
    return savedGames;
}

array<Pile,7> TableLoaderFileSystem::deserializePiles() {
    array<Pile,7> piles;
    array<string, 2> stackSerialization;
    for (int i=0; i < 7; i++) {
	stackSerialization = findElement("pile " + to_string(i));
	piles[i].putCardOnTop(deserializeCardStack(stackSerialization[1]));
    }
    return piles;
}

array<Foundation,4> TableLoaderFileSystem::deserializeFoundations() {
    array<Foundation,4> foundations;
    array<string, 2> stackSerialization;
    for (int i=0; i < 4; i++) {
	stackSerialization = findElement("foundation " + to_string(i));
	foundations[i].putCardOnTop(deserializeCardStack(stackSerialization[1]));
    }
    return foundations;
}

GameCardStack TableLoaderFileSystem::deserializeGameCardStack(string element) {
    array<string, 2> serialization = findElement(element);
    GameCardStack gameCardStack;
    gameCardStack.putCardOnTop(deserializeCardStack(serialization[1]));
    return gameCardStack;
}

vector<Card> TableLoaderFileSystem::deserializeCardStack(string stackSerialized) {
    vector<Card> cardStack;
    array<string,2> stackLeft = {"", stackSerialized};
    while (!(stackLeft = findCard(stackLeft[1]))[0].empty()) {
	cardStack.push_back(deserializeCard(stackLeft[0]));
    }
    return cardStack;
}

Card TableLoaderFileSystem::deserializeCard(string cardSerialized) {
    array<string,3> cardElements;
    size_t position;
    for (int i=0; i<cardElements.size(); i++) {
	position = cardSerialized.find(delimiters[1]);
	cardElements[i] = cardSerialized.substr(0, position);
	cardSerialized.erase(0, position + delimiters[1].length());
    }

    SuitFlyweightFactory suitFactory;
    Card card(stoi(cardElements.at(0)), suitFactory.getSuitIfExists(cardElements.at(1)));

    if (cardElements.at(2) == "1") {
	card.upTurn();
    }
    return card;
}

array<string,2> TableLoaderFileSystem::findElement(string element) {
    savingFile.open(directory + "/" + savingName + extension);
    array<string,2> foundElement;
    regex pattern("(" + element + ".*)(" + delimiters[0] + ")(.*)");
    smatch matches;
    string line;

    while(getline(savingFile, line)){
	if(regex_match(line, matches, pattern)){
	    foundElement[0] = matches[1];
	    foundElement[1] = matches[3];
	    break;
	}
    }
    savingFile.close();
    return foundElement;
}

array<string,2> TableLoaderFileSystem::findCard(string cards) {
    array<string,2> foundCard;
    size_t position;
    position = cards.find(delimiters[2]);
    if (position != std::string::npos) {
	foundCard[0] = cards.substr(0, position);
	foundCard[1] = cards.erase(0, position + delimiters[2].length());
    }

    return foundCard;
}
