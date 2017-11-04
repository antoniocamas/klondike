/*
 * CardStackRepresenter.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#include "CardStackView.h"

#include <vector>
#include <string>
#include <algorithm>

#include "Card.h"

using namespace std;

namespace card {

CardStackView::~CardStackView() {
	// TODO Auto-generated destructor stub
}

CardStackView& CardStackView::operator =(
		CardStackView other) {
	this->beginIt = other.beginIt;
	this->endIt = other.endIt;
	return *this;
}

vector<string> CardStackView::upTurnedCards2String() {
	vector<string> cardsString;
	for (auto it = this->beginIt; it != this->endIt; ++it) {
		if ((*it).isUpTurned())
			cardsString.push_back(this->representCard((*it)));
	}
	return cardsString;
}

vector<string> CardStackView::topCard2String(int numberOfCards) {
	vector<string> cardsString;
	vector<Card>::const_iterator firstCardIt;

	if (numberOfCards > this->getNumberOfCardsInTheStack())
		firstCardIt = this->beginIt;
	else
		firstCardIt = this->endIt - numberOfCards;

	for (vector<Card>::const_iterator it = firstCardIt; it != this->endIt; ++it){
		cardsString.push_back(this->representCard((*it)));
	}
	return cardsString;
}

string CardStackView::topCard2String() {
	vector<string> cardsString = this->topCard2String(1);

	if (cardsString.empty())
		return "";

	return cardsString.at(0);
}

vector<string> CardStackView::allCard2String() {
	return this->topCard2String(this->getNumberOfCardsInTheStack());
}

string CardStackView::representCard(Card card){
	return card.card2string();
}

int CardStackView::getNumberOfCardsInTheStack() {
	return distance(this->beginIt, this->endIt);
}

} /* namespace card */
