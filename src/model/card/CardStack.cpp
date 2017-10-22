/*
 * CardStack.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: antonio
 */

#include "CardStack.h"

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "Card.h"

//debug
#include <iostream>

using namespace card;

namespace card {

CardStack::~CardStack() {
	// TODO Auto-generated destructor stub
}

void CardStack::putCardOnTop(vector<Card> otherCards) {
	this->cards.insert(this->cards.end(),
			otherCards.begin(), otherCards.end());
}

Card CardStack::giveTopCardAway() {
	Card topCard;
	topCard = this->cards.back();
	this->cards.pop_back();
	return topCard;
}

vector<Card> CardStack::giveTopCardAway(int numberOfCards) {
	vector<Card> topCards;

	int cards2give = std::min(size_t(numberOfCards), this->cards.size());
	for (int i=0; i < cards2give; ++i){
		topCards.push_back(this->giveTopCardAway());
	}
	return topCards;
}

vector<Card> CardStack::getUpTurnedCards() {
	vector<Card> upTurnedCards;

	for (Card card : this->cards) {
		if (card.isUpTurned()) {
			upTurnedCards.push_back(card);
		}
	}
	return upTurnedCards;
}

vector<Card>::iterator CardStack::findCard(Card card) {
	for (vector<Card>::iterator it = this->cards.begin(); it != this->cards.end(); ++it)
		if (card == (*it)){ return it;}

	return this->cards.end();
}

bool CardStack::isPuttingDownPossible(Card inCommingCard) const {

	cout << "debug: In CardStack is Putting Down Possible: " << inCommingCard.card2string() << endl;
	return false;
}

CardStackRepresenter CardStack::getCardsRepresenter() const {
	return CardStackRepresenter(
			vector<Card>::const_iterator(this->cards.begin()),
			vector<Card>::const_iterator(this->cards.end()));
}

int CardStack::randomGenerator (int i) {
	std::srand ( unsigned ( std::time(0) ) );
	return std::rand()%i;
}

void CardStack::shuffle() {
	std::random_shuffle(this->cards.begin(), this->cards.end(),
			&CardStack::randomGenerator);
}

} /* namespace card */

