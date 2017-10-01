/*
 * UInterface.h
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#ifndef UINTERFACE_H_
#define UINTERFACE_H_

#include <iostream>
#include <string>
#include "TableLayout.h"

using namespace std;

namespace klondike {

class UInterface {

TableLayout table;

public:
	UInterface(){};
	void inline updateTable(TableLayout &t){table = t;}
	void printTableLayout(void);
	static void inline printMessage(const string message) { cout << message << endl; }
	virtual ~UInterface();
};

} /* namespace klondike */

#endif /* UINTERFACE_H_ */
