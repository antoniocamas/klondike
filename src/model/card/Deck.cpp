
#include <map>
#include <string>
#include <memory>
#include "Card.h"
#include "Deck.h"
#include "SuitFlyweightFactory.h"

using namespace std;

namespace card {

Deck::Deck(const int numberOfCardsPerSuit, const map<string, string> suitsDefinition) {
	SuitFlyweightFactory suitFlyweightFactory;

	for (auto s=suitsDefinition.begin(); s != suitsDefinition.end(); ++s)
	{
		shared_ptr<Suit> suit = suitFlyweightFactory.getSuit((*s).first, (*s).second, numberOfCardsPerSuit);
		for (int j=1; j < numberOfCardsPerSuit + 1; ++j)
		{
			this->cards.push_back(Card(j, suit));
		}
	}
}

}
