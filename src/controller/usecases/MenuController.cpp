
#include "MenuController.h"

MenuController::MenuController(std::shared_ptr<Table> t, std::shared_ptr<View> v,
			       State& s): Controller(t, v), state(s) {
};

void MenuController::control() {
    this->view->accept(this);
}

void MenuController::visit(OptionMenu option) {
    state = optionStateMap[option.getValue()];
}
	
