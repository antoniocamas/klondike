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
	virtual ~Klondike(){};

	void play();
};

#endif /* KLONDIKE_H_ */
