
#include "ViewConsoleLinux.h"
#include "ViewGameConsoleLinux.h"
#include "ViewMenuConsoleLinux.h"


void ViewConsoleLinux::accept(MenuController* controller) {
    ViewMenuConsoleLinux viewMenu =  ViewMenuConsoleLinux();
    viewMenu.showMenu();
    controller->visit(viewMenu.getOption());

}

void ViewConsoleLinux::accept(InGameController* controller) {
    ViewGameConsoleLinux viewGame(table);
    viewGame.showTable();
    controller->visit(viewGame.getNextMovement());
}
