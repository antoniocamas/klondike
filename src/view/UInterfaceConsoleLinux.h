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
#include <vector>
#include <string>
#include <memory>

#include "Table.h"
#include "ActionController.h"
#include "IOConsoleLinux.h"

using namespace std;

class UInterfaceConsoleLinux {

IOConsoleLinux io;
Table * table;

public:
	UInterfaceConsoleLinux(Table * table){ this->table = table;};
	virtual ~UInterfaceConsoleLinux();
	void showTable();
	shared_ptr<ActionController> getAction();
	static void inline printMessage(const string message) { cout << message << endl; }
};

void clear_screen();

#endif /* UINTERFACE_H_ */
