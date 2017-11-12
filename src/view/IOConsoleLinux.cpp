/*
 * IOConsoleLinux.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include "StringHandler.h"
#include "IOConsoleLinux.h"

using namespace std;

IOConsoleLinux::IOConsoleLinux(std::map<string, string>& tableElementRepresenter) {
	this->tableElementRepresenter = tableElementRepresenter;
}

void IOConsoleLinux::printNewLine() {
	cout << endl;
}

void IOConsoleLinux::printMessage(string message) {
	cout << message;
}

void IOConsoleLinux::printSplitter() {
	cout << string(80, '-') << endl;
}

void IOConsoleLinux::printHeader() {
	clear_screen();
	this->printMessage("\t\tKlondike\n");
	this->printSplitter();
}

void IOConsoleLinux::printRemainder(bool cardLeft) {
	string representation = this->getBasicRepresentation("remainder");
	if (cardLeft)
		representation += "[" + \
		     this->tableElementRepresenter["backCard"] + "]";
	else
		representation += ")   ";

	cout << representation << " ";
}

void IOConsoleLinux::printWaste(vector<string> cardsRepresentation) {
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

void IOConsoleLinux::printFoundation(vector<string> cardsRepresentation,
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

void IOConsoleLinux::printPile(vector<string> cardsRepresentation, int pileNumber) {
	string representation = this->getBasicRepresentation("pile", pileNumber);
	for (auto card : cardsRepresentation)
		representation += "[" + card;
	if (!cardsRepresentation.empty())
		representation += "]";
	else
		representation += " )";
	cout << representation << endl;
}

string IOConsoleLinux::getInput() {
	string input;
	cin >> input;
	StringHandler stringHandler(input);
	stringHandler.lowercase();
	return stringHandler.getString();
}

string IOConsoleLinux::getBasicRepresentation(string element, int number){
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

void clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}
