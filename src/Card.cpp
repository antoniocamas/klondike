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

bool Card::operator ==(Card otherCard) const {
	return this->number == otherCard.number and this->suit == otherCard.suit;
}

Card& Card::operator =(Card other) {
	this->number = other.number;
	this->suit = other.suit;
	this->upTurned = other.upTurned;
	return *this;
}

string Card::card2string() const {
	return this->suit.getNickName(this->number) + " " + this->suit.getName();
}

//string Card::getCardRepesentation() const {
//	if (!this->isUpTurned())
//		return "";
//
//	return this->suit.getNickName(this->number) + " " + this->suit.getShortName();
//}

}
