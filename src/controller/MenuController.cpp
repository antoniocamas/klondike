#include "MenuController.h"

void MenuController::control() {
    this->view->accept(this);
    state = State::INGAME;
}
