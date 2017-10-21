/*
 * Klondike.h
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#ifndef KLONDIKE_H_
#define KLONDIKE_H_

#include "Table.h"

class Klondike {
private:
Table table;

public:
	Klondike(){};

	void startGame();
	virtual ~Klondike();
};

#endif /* KLONDIKE_H_ */
