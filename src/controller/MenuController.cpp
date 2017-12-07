#include "MenuController.h"

void MenuController::control() {
    this->view->accept(this);
}

void MenuController::visit(Option option) {
    switch(option.getValue()){
    case 1:
	state = State::INGAME;
	break;
    case 2:
	state = State::INGAME;
	break;
    case 3:
	state = State::EXIT;
	break;
    default:
	break;
    }
}
	
