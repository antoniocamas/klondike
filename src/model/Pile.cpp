/*
 * Pile.cpp
 *
 *  Created on: Oct 12, 2017
 *      Author: antonio
 */

#include <vector>
#include "Pile.h"

using namespace std;
using namespace card;

Pile::Pile() {
	// TODO Auto-generated constructor stub

}

Pile::~Pile() {
	// TODO Auto-generated destructor stub
}

vector<Card> Pile::giveTopCardAway(Card fistCard2Lift) {
	vector<Card> cards2Return;
	vector<Card>::iterator it = this->findCard(fistCard2Lift);

	cards2Return.assign(it, this->cards.end());
	this->cards.resize(distance(this->cards.begin(), it));

	return cards2Return;
}

bool Pile::isPuttingDownPossible(Card inCommingCard) {
	if (this->cards.empty())
		return inCommingCard.isLastNumberOfSuit();

	return this->cards.back().isReverseConsecutiveNumber(inCommingCard) and
			!(this->cards.back().isSameColor(inCommingCard));
}
