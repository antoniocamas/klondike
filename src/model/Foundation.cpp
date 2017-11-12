/*
 * Foundation.cpp
 *
 *  Created on: Oct 12, 2017
 *      Author: antonio
 */

#include "Foundation.h"

using namespace card;

bool Foundation::isComplete() const {
	if (this->cards.empty())
			return false;

	return this->cards.back().isLastNumberOfSuit();
}

bool Foundation::isPuttingDownPossible(Card inCommingCard) const {
	if (this->cards.empty())
		return inCommingCard.isFirstNumberOfSuit();

	return this->cards.back().isConsecutiveNumber(inCommingCard) and
			this->cards.back().isSameSuit(inCommingCard);
}
