/*
 * UIConsoleLinux.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#include "UIConsoleLinux.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

UIConsoleLinux::UIConsoleLinux() {
	// TODO Auto-generated constructor stub

}

UIConsoleLinux::~UIConsoleLinux() {
	// TODO Auto-generated destructor stub
}

string UIConsoleLinux::niceConsoleCard(string card) {

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

void UIConsoleLinux::printNewLine() {
	cout << endl;
}

void UIConsoleLinux::printMessage(string message) {
	cout << message << endl;
}

void UIConsoleLinux::printSplitter() {
	cout << string(60, '-') << endl;
}

void UIConsoleLinux::printHeader() {
	clear_screen();
	this->printMessage("  Klondike - Enter your movement");
	this->printSplitter();
}

void UIConsoleLinux::printRemainder(bool cardLeft) {
	string remainderRepresentation;
	if (cardLeft)
		remainderRepresentation = "[" + string(1,backCardRepresentation) + "]";
	else
		remainderRepresentation = "   ";

	cout << "R: " << remainderRepresentation << " ";
}

void UIConsoleLinux::printWaste(vector<string> cardsRepresentation) {
	cout << "W: (";
	for (auto card : cardsRepresentation)
		cout << "[" << this->niceConsoleCard(card);
	if (!cardsRepresentation.empty())
		cout << "]";
	else
		cout << " ";

	cout << ")   ";
}

void UIConsoleLinux::printFoundation(string cardsRepresentation,
		int foundationNumber) {

	cout << "F" << foundationNumber << "(";
	if (!cardsRepresentation.empty())
		cout << "]";
	else
		cout << " ";
	cout << ")   ";
}

void UIConsoleLinux::printPile(vector<string> cardsRepresentation,
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
