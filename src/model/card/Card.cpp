#include "Card.h"
#include "Suit.h"

namespace card {
Card::Card(unsigned int number, shared_ptr<Suit> suit) {
	if (suit->isLastNumberOfSuit(0))
		this->number = 0;
	else
		this->number = number;
	this->suit = suit;
	this->upTurned = false;
}

bool Card::operator ==(Card otherCard) const {
	return this->number == otherCard.number and *this->suit == *otherCard.suit;
}

Card& Card::operator =(Card other) {
	this->number = other.number;
	this->suit = other.suit;
	this->upTurned = other.upTurned;
	return *this;
}
}
