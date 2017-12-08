
#include <memory>
#include "Logic.h"
#include "Controller.h"
#include "InGameController.h"
#include "MenuController.h"
#include "UndoController.h"
#include "RedoController.h"

using namespace std;

shared_ptr<Controller> Logic::getController() {
    shared_ptr<Controller> controller;

    switch(state){
    case State::NEWGAME:
	createNewGame();
	state = State::INGAME;
	break;
    case State::INGAME:
	controller = make_shared<InGameController>(table.get(), view, state, tableRegistry.get());
	break;
    case State::MENU:
	controller = make_shared<MenuController>(table.get(), view, state);
	break;
    case State::UNDO:
	controller = make_shared<UndoController>(table.get(), view, tableRegistry.get());
	state = State::INGAME;
	break;
    case State::REDO:
	controller = make_shared<RedoController>(table.get(), view, tableRegistry.get());
	state = State::INGAME;
	break;
    case State::FINISH:
	state = State::MENU;
	break;
    default:
	break;
    }

    return controller;
}

void Logic::createNewGame() {
    table = make_shared<Table>();
    view->setTable(table.get());
    tableRegistry = std::make_shared<TableRegistry>();
    tableRegistry->updateHistory(table.get());
}
