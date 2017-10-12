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

//Deck::Deck() {
//this->Deck(nCards, suitsDefinition)	;
//}

Deck::Deck(const int nCards, const map<string, string> suitsDefinition,
		const map<int, string> nicknames) {

	this->numberOfCardsPerSuit = nCards;

	for (auto s=suitsDefinition.begin(); s != suitsDefinition.end(); ++s)
	{
		Suit suit = Suit((*s).first, (*s).second, nCards, nicknames);
		for (int j=1; j < this->numberOfCardsPerSuit + 1; ++j)
		{
			this->cards.push_back(Card(j,suit));
		}
	}
}


}
