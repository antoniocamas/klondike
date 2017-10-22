/*
 * Tableau.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include <string>
#include "Table.h"
#include "Foundation.h"

// debug
#include <iostream>
#include "Deck.h"

Table::Table() {
	this->deal();
}

Table::~Table() {
	// TODO Auto-generated destructor stub
}

void Table::deal()
{
	card::Deck deck;
	deck.shuffle();
	Card card;

	for (int pilesFull = 0; pilesFull < numberOfPiles; ++pilesFull) {
		for (int i=7 ; i > pilesFull-1 ; --i){
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
//void Tableau::applyMovement(Movement movement) {
//	std::string::size_type sz;
//	switch (std::stoi(movement.getStackDestination(), sz)){
//	case stoi("foundation, sz"):
//		cout << "Foundation detected" << endl;
//		this->foundations.at(movement.getDestinationIndex()).isPuttingDownPossible(movement.getCardOrigin());
//		break;
//	case stoi("pile", sz):
//		this->piles.at(movement.getDestinationIndex()).isPuttingDownPossible(movement.getCardOrigin());
//		break;
//	}
//
//}
