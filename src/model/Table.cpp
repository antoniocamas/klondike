/*
 * Tableau.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */


#include "Table.h"
#include "Deck.h"

Table::Table(){
	this->deal();
}

void Table::deal()
{
	card::Deck deck;
	deck.shuffle();
	card::Card card;

	for (int pilesFull = 0; pilesFull < numberOfPiles; ++pilesFull) {
		for (int i=piles.size()-1 ; i > pilesFull-1 ; --i){
			card = deck.giveTopCardAway();
			if (i == pilesFull)
				card.upTurn();
			this->piles[i].putCardOnTop(card);
		}
	}
	this->remainder.putCardOnTop(deck.giveTopCardAway(deck.getNumberOfCards()));
}

bool Table::areAllFoundationsComplete() const {
	for (unsigned int i = 0; i < this->foundations.size(); ++i){
		if(!this->foundations[i].isComplete())
			return false;
	}

	return true;
}
