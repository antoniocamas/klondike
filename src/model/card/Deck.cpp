/*
 * Deck.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include <map>
#include <string>
#include "Card.h"
#include "Deck.h"

using namespace std;

namespace card {

Deck::Deck(const int numberOfCardsPerSuit, const map<string, string> suitsDefinition) {
	for (auto s=suitsDefinition.begin(); s != suitsDefinition.end(); ++s)
	{
		Suit suit = Suit((*s).first, (*s).second, numberOfCardsPerSuit);
		for (int j=1; j < numberOfCardsPerSuit + 1; ++j)
		{
			this->cards.push_back(Card(j,suit));
		}
	}
}

}
