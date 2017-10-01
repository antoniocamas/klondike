/*
 * Deck.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include <iostream>
#include <algorithm>
#include "Deck.h"
#include "Card.h"

Deck::Deck() {

	suits[clubs] = black;
	suits[diamonds] = red;
	suits[hearts] = red;
	suits[spades] = black;

	st_suit suit;
	for (auto s=suits.begin(); s != suits.end(); ++s)
	{
		 suit.name = (*s).first;
		 suit.color = (*s).second;
		for (int j=1; j < this->cards_per_suit + 1; ++j)
		{
			this->cards.push_back(Card(j,suit));

		}
	}

	std::random_shuffle(this->cards.begin(), this->cards.end());
	this->printDeck();
}

Deck::~Deck() {
	// TODO Auto-generated destructor stub
}

void Deck::printDeck()
{
	for (auto card = this->cards.begin(); card != this->cards.end(); ++card)
		std::cout << (*card).card2string() << std::endl;
}

