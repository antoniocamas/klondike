/*
 * Suit.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: antonio
 */

#include "Suit.h"
#include <string>

using namespace std;
using namespace card;

namespace card {

Suit::Suit(string name, string color) {
	this->name = name;
	this->color = color;
}

Suit::~Suit() {
	// TODO Auto-generated destructor stub
}

} /* namespace card */

Suit& Suit::operator =(Suit other) {
	this->name = other.name;
	this->color = other.color;
	return *this;
}
