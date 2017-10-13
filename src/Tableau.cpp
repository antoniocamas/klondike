/*
 * Tableau.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include "Tableau.h"
#include "Deck.h"

// debug
#include <iostream>

Tableau::Tableau() {
	this->deal();
}

Tableau::~Tableau() {
	// TODO Auto-generated destructor stub
}

void Tableau::deal()
{
	card::Deck deck;
	deck.shuffle();
	Card card;

	for (int pilesFull = 0; pilesFull < 7; ++pilesFull) {
		for (int i=7 ; i > pilesFull-1 ; --i){
			card = deck.giveTopCardAway();
			if (i == pilesFull)
				card.upTurn();
			this->piles[i].putCardOnTop(card);
		}
	}
	this->remainder.putCardOnTop(deck.giveTopCardAway(deck.getNumberOfCards()));
}
