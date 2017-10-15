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

#include "../Tableau.h"
#include "UIConsoleLinux.h"

using namespace std;

class UInterface {

UIConsoleLinux io;

public:
	UInterface(){};
	virtual ~UInterface();
	void showTableau(Tableau &t);
	static void inline printMessage(const string message) { cout << message << endl; }

};

void clear_screen();

#endif /* UINTERFACE_H_ */
