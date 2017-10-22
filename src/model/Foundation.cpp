/*
 * Foundation.cpp
 *
 *  Created on: Oct 12, 2017
 *      Author: antonio
 */

#include "Foundation.h"

using namespace card;

Foundation::Foundation() {
	// TODO Auto-generated constructor stub

}

Foundation::~Foundation() {
	// TODO Auto-generated destructor stub
}

bool Foundation::isComplete() const {
	if (this->cards.empty())
			return false;

	return this->cards.back().isLastNumberOfSuit();
}

bool Foundation::isPuttingDownPossible(Card inCommingCard) const {
#include <iostream>
	std::cout << "In foundation" << std::endl;

	if (this->cards.empty())
		return inCommingCard.isFirstNumberOfSuit();

	return this->cards.back().isConsecutiveNumber(inCommingCard) and
			this->cards.back().isSameSuit(inCommingCard);
}
