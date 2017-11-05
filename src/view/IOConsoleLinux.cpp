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
		representation += "[" + this->niceConsoleCard(card);
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
		representation += "[" + this->niceConsoleCard(card);
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
		representation += "[" + this->niceConsoleCard(card);
	if (!cardsRepresentation.empty())
		representation += "]";
	else
		representation += " )";
	cout << representation << endl;
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

string IOConsoleLinux::getBasicRepresentation(string element, int number){
	string representation;
	representation = this->tableElementRepresenter[element];
	this->uppercase(&representation);
	if (number != 0)
		representation += to_string(number);
	representation += ":(";
	return representation;
}

