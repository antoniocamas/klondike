/*
 * Foundation.h
 *
 *  Created on: Oct 12, 2017
 *      Author: antonio
 */

#ifndef FOUNDATION_H_
#define FOUNDATION_H_

#include "Pile.h"
#include "Card.h"

using namespace card;

class Foundation: public Pile {
public:
	Foundation();
	virtual ~Foundation();
	bool isComplete();
	bool isPuttingDownPossible(Card inCommingCard) const;

};

#endif /* FOUNDATION_H_ */
