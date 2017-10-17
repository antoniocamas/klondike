/*
 * Klondike.h
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#ifndef KLONDIKE_H_
#define KLONDIKE_H_

#include "Tableau.h"

class Klondike {
private:
Tableau tableau;

public:
	Klondike(){};

	void startGame();
	virtual ~Klondike();
};

#endif /* KLONDIKE_H_ */
