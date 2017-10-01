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

Deck::Deck() {

	suits["clubs"] = "black";
	suits["diamonds"] = "red";
	suits["hearts"] = "red";
	suits["spades"] = "black";

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

	cout << this->deck2string();
}

string Deck::deck2string()
{
	string deck_repr = "";
	for (auto card = this->cards.begin(); card != this->cards.end(); ++card)
		  deck_repr += (*card).card2string() + "\n";
	return deck_repr;
}

