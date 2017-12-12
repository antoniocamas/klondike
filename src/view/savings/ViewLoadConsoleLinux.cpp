#include "ViewLoadConsoleLinux.h"

ViewLoadConsoleLinux::ViewLoadConsoleLinux(vector<string> savedGames) {
    vector<OptionMenu> menuOptions;

    for (int i=0; i < savedGames.size(); i++) {
	menuOptions.push_back(OptionMenu(i+1, savedGames[i]));
    }

    menu = make_shared<MenuText>(menuOptions);
}

void ViewLoadConsoleLinux::showSavedGames() {
    menu->showMenu("Saved Games");
}

string ViewLoadConsoleLinux::getSavingName() {
    string input;
    return menu->getOption().getString();
}
