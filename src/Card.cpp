/*
 * Card.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include <string>
#include "Card.h"
#include "Suit.h"

namespace card {
Card::Card(int number, Suit suit) {
	this->number = number;
	this->suit = suit;
	this->upTurned = false;
}

Card::~Card() {
	// TODO Auto-generated destructor stub
}

string Card::card2string() {

	return std::to_string(this->number) + ", " + this->suit.getName();
}

}
