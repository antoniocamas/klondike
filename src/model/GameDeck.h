/*
 * GameDeck.h
 *
 *  Created on: Nov 11, 2017
 *      Author: antonio
 */

#ifndef SRC_MODEL_GAMEDECK_H_
#define SRC_MODEL_GAMEDECK_H_

#include "Deck.h"
#include "Configurator.h"

class GameDeck: public card::Deck {
public:
	GameDeck(): card::Deck(Configurator::getInstance()->getSuitNumberOfCards(),
				Configurator::getInstance()->getSuitModel()){};
	virtual ~GameDeck(){};
};

#endif /* SRC_MODEL_GAMEDECK_H_ */
