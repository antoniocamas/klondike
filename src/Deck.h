/*
 * Deck.h
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <string>
#include <map>
#include "Card.h"

using namespace std;

class Deck {
private:
	map<string, string> suits;
	//int number_of_suits = 4;
	int cards_per_suit = 2;
	vector<Card> cards;

public:
	Deck();
	string deck2string();
	virtual ~Deck(){};
};

#endif /* DECK_H_ */
