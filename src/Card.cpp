/*
 * Card.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include "Card.h"

Card::Card(int n, st_suit s) {
	this->number=n;
	this->suit.name=s.name;
	this->suit.color=s.color;
}

Card::~Card() {
	// TODO Auto-generated destructor stub
}

