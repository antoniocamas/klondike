/*
 * Deck.h
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <map>
#include "Card.h"

using namespace std;

typedef enum suit_name
{
	clubs,
	diamonds,
	hearts,
	spades,
}en_suit_name;

typedef enum suit_color
{
	black,
	red,
}en_suit_color;


class Deck {
private:
	map<en_suit_name, en_suit_color> suits;
	//int number_of_suits = 4;
	int cards_per_suit = 2;
	vector<Card> cards;

public:
	Deck();
	void printDeck();
	virtual ~Deck();
};

#endif /* DECK_H_ */
