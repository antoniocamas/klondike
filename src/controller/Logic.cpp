
#include <memory>
#include "Logic.h"
#include "Controller.h"
#include "InGameController.h"
#include "MenuController.h"

using namespace std;

shared_ptr<Controller> Logic::getController() {
    shared_ptr<Controller> controller;

    switch(state){
    case State::NEWGAME:
	createNewGame();
	state = State::INGAME;
	break;
    case State::MENU:
	controller = make_shared<MenuController>(table.get(), view, state);
	break;
    case State::INGAME:
	controller = make_shared<InGameController>(table.get(), view, state);
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
}
