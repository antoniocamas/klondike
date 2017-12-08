
#include "MenuController.h"

void MenuController::control() {
    this->view->accept(this);
}

void MenuController::visit(Option option) {
    state = optionStateMap[option.getValue()];
}
	
