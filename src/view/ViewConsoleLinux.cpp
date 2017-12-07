#include "ViewConsoleLinux.h"
#include "ViewGameConsoleLinux.h"

#include <iostream>
using namespace std;

void ViewConsoleLinux::accept(MenuController* controller) {
    std::cout << "In Menu" << std::endl;
}

void ViewConsoleLinux::accept(InGameController* controller) {
    ViewGameConsoleLinux viewGame(table);
    viewGame.showTable();
    controller->visit(viewGame.getNextMovement());
}
