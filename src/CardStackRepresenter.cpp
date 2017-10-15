/*
 * CardStackRepresenter.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#include <vector>
#include <string>
#include <algorithm>
#include "CardStackRepresenter.h"
#include "Card.h"

using namespace std;

namespace card {

CardStackRepresenter::~CardStackRepresenter() {
	// TODO Auto-generated destructor stub
}

CardStackRepresenter& CardStackRepresenter::operator =(
		CardStackRepresenter other) {
	this->beginIt = other.beginIt;
	this->endIt = other.endIt;
	return *this;
}

vector<string> CardStackRepresenter::upTurnedCards2String() {
	vector<string> cardsString;
	for (auto it = this->beginIt; it != this->endIt; ++it) {
		if ((*it).isUpTurned())
			cardsString.push_back(this->representCard((*it)));
	}
	return cardsString;
}

vector<string> CardStackRepresenter::topCard2String(int numberOfCards) {
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

string CardStackRepresenter::topCard2String() {
	vector<string> cardsString = this->topCard2String(1);

	if (cardsString.empty())
		return "";

	return cardsString.at(0);
}

vector<string> CardStackRepresenter::allCard2String() {
	return this->topCard2String(this->getNumberOfCardsInTheStack());
}

string CardStackRepresenter::representCard(Card card) const {
	return card.card2string();
}

int CardStackRepresenter::getNumberOfCardsInTheStack() {
	return distance(this->beginIt, this->endIt);
}

} /* namespace card */
