/*
 * UInterface.h
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 *
 *  This module is OS system dependent. This implementation is meant for Linux Terminal.
 *
 */

#ifndef UINTERFACE_H_
#define UINTERFACE_H_

#include <iostream>
#include <string>

#include "Tableau.h"

using namespace std;

namespace klondike {

class UInterface {

Tableau table;

public:
	UInterface(){};
	void inline updateTable(Tableau &t){table = t;}
	void printTableLayout(void);
	static void inline printMessage(const string message) { cout << message << endl; }
	virtual ~UInterface();
};

void clear_screen();

} /* namespace klondike */

#endif /* UINTERFACE_H_ */
