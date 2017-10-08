/*
 * Deck.h
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#ifndef DECK_H_
#define DECK_H_

#include <map>
#include <string>
#include "CardStack.h"

using namespace std;

namespace card {

const int nCards = 13;
const map<string, string> suits = {
		{"clubs", "black"},
		{"diamonds", "red"},
		{"spades", "black"},
		{"hearts", "red"}
};

class Deck: public CardStack {
private:
	int numberOfCardsPerSuit;
public:
	Deck();
	virtual ~Deck(){};
};

}
#endif /* DECK_H_ */
