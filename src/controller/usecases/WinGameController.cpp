#include "WinGameController.h"

WinGameController::WinGameController(
    std::shared_ptr<Table> t, std::shared_ptr<View> v): Controller(t, v) {
};

void WinGameController::control() {
    view->accept(this);
}
