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
#include "Configurator.h"

using namespace std;

namespace card {

class Deck: public CardStack {
private:
	int numberOfCardsPerSuit;
public:
	Deck(): Deck(Configurator::getInstance()->getSuitNumberOfCards(),
			Configurator::getInstance()->getSuitModel()){};
	Deck(const int nCards, const map<string, string> suitsDefinition);
	virtual ~Deck(){};
};

}
#endif /* DECK_H_ */
