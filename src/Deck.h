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
const map<string, string> frenchSuits = {
		{"clubs", "black"}, {"diamonds", "red"},
		{"spades", "black"}, {"hearts", "red"}
};

const map<int, string> frechNicknames = {
		{1, "A"}, {11, "J"}, {12, "Q"}, {13, "K"}
};
const map<string, string> othersuits = {
		{"bastos", "verde"}, {"copas", "rojo"},
		{"oros", "amarillo"}, {"espadas", "azul"}
};

const map<int, char> spanishNicknames = {};

class Deck: public CardStack {
private:
	int numberOfCardsPerSuit;
public:
	Deck(): Deck(nCards, frenchSuits, frechNicknames){}
	Deck(const int nCards, const map<string, string> suitsDefinition,
			const map<int, string> nicknames);
	virtual ~Deck(){};
};

}
#endif /* DECK_H_ */
