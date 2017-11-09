/*
 * Klondike.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include <memory>

#include "Klondike.h"
#include "Table.h"
#include "UInterfaceConsoleLinux.h"
#include "ActionController.h"


#include "View.h"
#include "Controller.h"

void Klondike::play()
{
	shared_ptr<ActionController> action;
	UInterfaceConsoleLinux uinterface(&table);
	do{
		uinterface.showTable();
		action = uinterface.getAction();
		if (action->isValid())
			action->execute();
	}while(!this->table.areAllFoundationsComplete());

	uinterface.showWinMessage();
}


