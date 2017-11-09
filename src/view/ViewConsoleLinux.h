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

#include "View.h"
#include "Table.h"
#include "ActionController.h"
#include "IOConsoleLinux.h"

using namespace std;

class ViewConsoleLinux: public View {

private:
	map<string,string> tableElementRepresenter = {
			{"remainder", "r"}, {"waste", "w"}, {"foundation","f"},
			{"pile", "p"}, {"backCard", "@"}, {"card", ".{1,2}[aA-zZ]"}
	};

	IOConsoleLinux io;

public:
	ViewConsoleLinux();
	virtual ~ViewConsoleLinux(){};
	void showTable();
	void showWinMessage();
	shared_ptr<ActionController> getAction();
	//void getNextMovement();
private:
	static void inline printMessage(const string message) { cout << message << endl; }
};

void clear_screen();

#endif /* UINTERFACE_H_ */
