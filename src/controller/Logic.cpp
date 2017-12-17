#include <memory>
#include "Logic.h"
#include "State.h"
#include "Controller.h"
#include "InGameController.h"
#include "WinGameController.h"
#include "MenuController.h"
#include "UndoController.h"
#include "RedoController.h"
#include "SaveController.h"
#include "LoadController.h"

using namespace std;

Logic::Logic(std::shared_ptr<View> v): state(State::NEWGAME),view(v), table(0) {
};

shared_ptr<Controller> Logic::getController() {
    shared_ptr<Controller> controller;

    switch(state){
    case State::NEWGAME:
	createNewGame();
	state = State::INGAME;
	break;
    case State::INGAME:
	controller = make_shared<InGameController>(table, view, state, tableRegistry);
	break;
    case State::MENU:
	controller = make_shared<MenuController>(table, view, state);
	break;
    case State::UNDO:
	controller = make_shared<UndoController>(table, view, tableRegistry);
	state = State::INGAME;
	break;
    case State::REDO:
	controller = make_shared<RedoController>(table, view, tableRegistry);
	state = State::INGAME;
	break;
    case State::SAVE:
	controller = make_shared<SaveController>(table, view);
	state = State::INGAME;
	break;
    case State::LOAD:
	controller = make_shared<LoadController>(table, view, tableRegistry);
	state = State::INGAME;
	break;
    case State::FINISH:
	controller = make_shared<WinGameController>(table, view);
	state = State::MENU;
	break;
    default:
	break;
    }

    return controller;
}

bool Logic::isTimeToExit() {
    return (state == State::EXIT);
}

void Logic::createNewGame() {
    table = make_shared<Table>();
    view->setTable(table.get());
    tableRegistry = std::make_shared<TableRegistry>();
    tableRegistry->updateHistory(table.get());
}
