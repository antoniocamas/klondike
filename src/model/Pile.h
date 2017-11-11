/*
 * Pile.h
 *
 *  Created on: Oct 12, 2017
 *      Author: antonio
 */

#ifndef PILE_H_
#define PILE_H_

#include "GameCardStack.h"
#include "Card.h"

using namespace card;
class Pile: public GameCardStack {
public:
	Pile(){};
	virtual ~Pile(){};
	using GameCardStack::giveTopCardAway;
	vector<Card> giveTopCardAway(Card fistCard2Lift);

	virtual bool isMovingTopStackPossible(Card);
	virtual bool isPuttingDownPossible(Card inCommingCard)const;

};

#endif /* PILE_H_ */
