/*
 * Pile2PileController.h
 *
 *  Created on: Nov 4, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_MOVEMENT_PILE2PILECONTROLLER_H_
#define SRC_CONTROLLER_MOVEMENT_PILE2PILECONTROLLER_H_

#include "Card.h"
#include "movement/MovementController.h"

using namespace card;

class Pile2PileController: public MovementController {
private:
	Card originCard;

public:
	Pile2PileController(Table * t, int origPile, int destPiler, Card card);
	virtual ~Pile2PileController(){};

	bool isValid();
	void applyMovement();
};

#endif /* SRC_CONTROLLER_MOVEMENT_PILE2PILECONTROLLER_H_ */
