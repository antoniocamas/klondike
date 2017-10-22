/*
 * UIConsoleLinux.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#include "IOConsoleLinux.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

IOConsoleLinux::IOConsoleLinux(std::map<string, string>& tableElementRepresenter) {
	this->tableElementRepresenter = tableElementRepresenter;
}

IOConsoleLinux::~IOConsoleLinux() {
	// TODO Auto-generated destructor stub
}

string IOConsoleLinux::niceConsoleCard(string card) {

string newCardRepresentation = card;
//	if (card.empty())
//		return card;
//
//	char suite = *(card.end()-1);
//	string number = card
//	switch (suite) {
//	case 'H':
//		RED + card + RESET;
//		break;
//	}
//	case
//
//	if (suite == 'H')
//		or suite == 'D')
//		return RED + card + RESET;
//
//	return BLACK + card + RESET;

	return newCardRepresentation;
}

void IOConsoleLinux::printNewLine() {
	cout << endl;
}

void IOConsoleLinux::printMessage(string message) {
	cout << message;
}

void IOConsoleLinux::printSplitter() {
	cout << string(60, '-') << endl;
}

void IOConsoleLinux::printHeader() {
	clear_screen();
	this->printMessage("\t\tKlondike\n");
	this->printSplitter();
}

void IOConsoleLinux::printRemainder(bool cardLeft) {
	string remainderRepresentation;
	remainderRepresentation = this->tableElementRepresenter["remainder"];
	this->uppercase(&remainderRepresentation);
	remainderRepresentation += ": ";
	if (cardLeft)
		remainderRepresentation += "[" + \
		     this->tableElementRepresenter["backCard"] + "]";
	else
		remainderRepresentation += "   ";

	cout << remainderRepresentation << " ";
}

void IOConsoleLinux::printWaste(vector<string> cardsRepresentation) {
	cout << "W: (";
	for (auto card : cardsRepresentation)
		cout << "[" << this->niceConsoleCard(card);
	if (!cardsRepresentation.empty())
		cout << "]";
	else
		cout << " ";

	cout << ")   ";
}

void IOConsoleLinux::printFoundation(string cardsRepresentation,
		int foundationNumber) {

	cout << "F" << foundationNumber << "(";
	if (!cardsRepresentation.empty())
		cout << "]";
	else
		cout << " ";
	cout << ")   ";
}

void IOConsoleLinux::printPile(vector<string> cardsRepresentation,
		int pileNumber) {

	cout << "P" << pileNumber << ": ";
	for (auto card : cardsRepresentation)
		cout << "[" << this->niceConsoleCard(card);
	if (!cardsRepresentation.empty())
		cout << "]";
	 cout << endl;
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

string IOConsoleLinux::getInput() {
	string input;
	cin >> input;
	lowercase(&input);
	return input;
}

void IOConsoleLinux::lowercase(string* message) {
	std::transform(message->begin(), message->end(), message->begin(), ::tolower);
}

void IOConsoleLinux::uppercase(string* message) {
	std::transform(message->begin(), message->end(), message->begin(), ::toupper);
}
