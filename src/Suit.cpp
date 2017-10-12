/*
 * Suit.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: antonio
 */
#include <iostream>
#include "Suit.h"
#include <string>

using namespace std;
using namespace card;

namespace card {

Suit::Suit(string name, string color,
		int numberOfCards, map<int, string> nicknames) {
	this->name = name;
	this->color = color;
	this->numberOfCardsperSuit = numberOfCards;
	this->nicknames = nicknames;
}

Suit::~Suit() {
	// TODO Auto-generated destructor stub
}

string Suit::getNickName(int number) {

	std::map<int,string>::iterator iterator;

	iterator = this->nicknames.find(number);
	if (iterator != this->nicknames.end())
		return iterator->second;

	return to_string(number);
}


} /* namespace card */

Suit& Suit::operator =(Suit other) {
	this->name = other.name;
	this->color = other.color;
	this->numberOfCardsperSuit = other.numberOfCardsperSuit;
	this->nicknames = other.nicknames;
	return *this;
}
