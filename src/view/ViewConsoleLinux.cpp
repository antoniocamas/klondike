#include "ViewConsoleLinux.h"
#include "ViewGameConsoleLinux.h"
#include "ViewMenuConsoleLinux.h"
#include "ViewLoadConsoleLinux.h"
#include "ViewSaveConsoleLinux.h"

void ViewConsoleLinux::accept(MenuController* controller) {
    ViewMenuConsoleLinux viewMenu = ViewMenuConsoleLinux();
    viewMenu.showMenu();
    controller->visit(viewMenu.getOption());

}

void ViewConsoleLinux::accept(InGameController* controller) {
    ViewGameConsoleLinux viewGame(table);
    viewGame.showTable();
    controller->visit(viewGame.getNextMovement());
}

void ViewConsoleLinux::accept(LoadController* controller) {
    ViewLoadConsoleLinux viewLoad(controller->getSavedGames());
    viewLoad.showSavedGames();
    controller->visit(viewLoad.getSavingName());
}

void ViewConsoleLinux::accept(SaveController* controller) {
    ViewSaveConsoleLinux viewSave = ViewSaveConsoleLinux();
    controller->visit(viewSave.getSavingName());
}

void ViewConsoleLinux::accept(WinGameController* controller) {
    ViewGameConsoleLinux viewGame(table);
    viewGame.showWinMessage();
}
