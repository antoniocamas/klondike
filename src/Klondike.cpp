/*
 * Klondike.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include <memory>

#include "Klondike.h"

#include "controller/Logic.h"
//#include "Table.h"
//#include "ActionController.h"

#include "ViewConsoleLinux.h"

//void Klondike::play()
//{
//	shared_ptr<ActionController> action;
//	UInterfaceConsoleLinux uinterface(&table);
//	do{
//		uinterface.showTable();
//		action = uinterface.getAction();
//		if (action->isValid())
//			action->execute();
//	}while(!this->table.areAllFoundationsComplete());
//
//	uinterface.showWinMessage();
//}

void Klondike::play(){
	std::shared_ptr<ViewConsoleLinux> view = std::make_shared<ViewConsoleLinux>();
	Logic logic(view);
	std::shared_ptr<Controller> controller;

	do{
		controller = logic.getController();
		if (controller)
			controller->control();
	}while(!logic.isTimeToExit());


}
