/*
 * Movement.h
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#ifndef SRC_MOVEMENT_H_
#define SRC_MOVEMENT_H_

#include "CardStack.h"
#include "Card.h"
#include "Tableau.h"

using namespace card;

class Movement {
private:

	TableauArea stackOrigin;
	int originIndex;
	string stackDestination;
	int destinationIndex;
	Card cardOrigin;

public:
	Movement(string stackOrigin, int originIndex, string stackDestination,
			int destinationIndex, Card cardOrigin);
	virtual ~Movement();

	const Card& getCardOrigin() const {return cardOrigin;}
//	CardStack& getStackDestination() {return stackDestination;}
//	CardStack getStackOrigin() const {return stackOrigin;}

	int getDestinationIndex() const {return destinationIndex;}
	int getOriginIndex() const {return originIndex;}
	const string& getStackDestination() const {return stackDestination;}
	const string& getStackOrigin() const {return stackOrigin;}
};

#endif /* SRC_MOVEMENT_H_ */
