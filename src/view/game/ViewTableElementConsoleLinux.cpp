
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include "StringHandler.h"
#include "ViewTableElementConsoleLinux.h"

using namespace std;

ViewTableElementConsoleLinux::ViewTableElementConsoleLinux(std::map<string, string>& tableElementRepresenter) {
    this->tableElementRepresenter = tableElementRepresenter;
}

void ViewTableElementConsoleLinux::printHeader() {
    clear_screen();
    this->printMessage("\t\tKlondike\n");
    this->printSplitter();
}

void ViewTableElementConsoleLinux::printMenuMessage() {
    
    StringHandler stringHandler(tableElementRepresenter["menu"]);
    stringHandler.uppercase();

    printSplitter();
    printMessage("\tPress '");
    printMessage(stringHandler.getString());
    printMessage("' at any moment to show the Menu \n");
}

void ViewTableElementConsoleLinux::printRemainder(bool cardLeft) {
    string representation = this->getBasicRepresentation("remainder");
    if (cardLeft)
	representation += "[" + \
	    this->tableElementRepresenter["backCard"] + "]";
    else
	representation += ")   ";

    cout << representation << " ";
}

void ViewTableElementConsoleLinux::printWaste(vector<string> cardsRepresentation) {
    string representation = this->getBasicRepresentation("waste");


    for (auto card : cardsRepresentation)
	representation += "[" + card;
    if (!cardsRepresentation.empty())
	representation += "]";

    else
	representation += " ";

    representation += ")  |  ";
    cout << representation;
}

void ViewTableElementConsoleLinux::printFoundation(vector<string> cardsRepresentation,
				     int foundationNumber) {

    string representation = this->getBasicRepresentation("foundation", foundationNumber);
    for (auto card : cardsRepresentation)
	representation += "[" + card;
    if (!cardsRepresentation.empty())
	representation += "]";
    else
	representation += " ";

    representation += ")   ";
    cout << representation;
}

void ViewTableElementConsoleLinux::printPile(vector<string> cardsRepresentation, int pileNumber) {
    string representation = this->getBasicRepresentation("pile", pileNumber);
    for (auto card : cardsRepresentation)
	representation += "[" + card;
    if (!cardsRepresentation.empty())
	representation += "]";
    else
	representation += " )";
    cout << representation << endl;
}

string ViewTableElementConsoleLinux::getBasicRepresentation(string element, int number){
    string representation;
    representation = this->tableElementRepresenter[element];
    StringHandler stringHandler(representation);
    stringHandler.uppercase();
    representation = stringHandler.getString();
    if (number != 0)
	representation += to_string(number);
    representation += ":(";
    return representation;
}
