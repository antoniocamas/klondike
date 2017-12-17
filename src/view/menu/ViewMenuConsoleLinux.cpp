#include <string>
#include "ViewMenuConsoleLinux.h"
#include "OptionMenu.h"

ViewMenuConsoleLinux::ViewMenuConsoleLinux() {
    vector<OptionMenu> menuOptions = {
	OptionMenu(1, "New Game"),
	OptionMenu(2, "Go back to Play"),
	OptionMenu(3, "Undo movement"),
	OptionMenu(4, "Redo movement"),
	OptionMenu(5, "Save Game"),
	OptionMenu(6, "Load Game"),
	OptionMenu(0, "Quit Klondike")};

    menu = make_shared<MenuText>(menuOptions);
};

ViewMenuConsoleLinux::~ViewMenuConsoleLinux() {
};

void ViewMenuConsoleLinux::showMenu() {
    menu->showMenu(" Klondike Menu");
}

const OptionMenu ViewMenuConsoleLinux::getOption() {
    return menu->getOption();
}
