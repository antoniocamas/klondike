/*
 * Suit.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: antonio
 */
#include "Suit.h"

#include <iostream>
#include <string>

using namespace std;
using namespace card;

namespace card {

Suit::Suit(string name, string color,
		int numberOfCards) {
	this->name = name;
	this->color = color;
	this->numberOfCardsperSuit = numberOfCards;
}

Suit& Suit::operator =(Suit other) {
	this->name = other.name;
	this->color = other.color;
	this->numberOfCardsperSuit = other.numberOfCardsperSuit;
	return *this;
}

} /* namespace card */
