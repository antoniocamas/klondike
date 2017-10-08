/*
 * Deck.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include <iostream>
#include <string>
#include <algorithm>
#include "Deck.h"
#include "Card.h"

using namespace std;

namespace card {

Deck::Deck() {
	this->numberOfCardsPerSuit = nCards;

	for (auto s=suits.begin(); s != suits.end(); ++s)
	{
		Suit suit = Suit((*s).first, (*s).second);
		for (int j=1; j < this->numberOfCardsPerSuit + 1; ++j)
		{
			this->cards.push_back(Card(j,suit));
		}
	}
}

}
