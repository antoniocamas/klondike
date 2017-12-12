
#include "MenuController.h"

void MenuController::control() {
    this->view->accept(this);
}

void MenuController::visit(OptionMenu option) {
    state = optionStateMap[option.getValue()];
}
	
