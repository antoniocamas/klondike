/*
 * Klondike.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include <vector>
#include <string>
#include <memory>

#include "Klondike.h"
#include "Table.h"
#include "UInterfaceConsoleLinux.h"
#include "ActionController.h"


Klondike::~Klondike() {
	// TODO Auto-generated destructor stub
}

void Klondike::startGame()
{
	shared_ptr<ActionController> action;
	UInterfaceConsoleLinux uinterface(&table);
	uinterface.showTable();
	action = uinterface.getAction();
	if (action->isValid())
		action->execute();
	uinterface.showTable();


}
