#include <string>
#include "MenuText.h"

using namespace std;

MenuText::MenuText(vector<OptionMenu> options): menuOptions(options), io() {
};

void MenuText::showMenu(string title) {
    clear_screen();
    io.printSplitter();
    io.printMessage("\t\t" + title + "\n");
    io.printSplitter();

    for (auto option : menuOptions) {
	io.printMessage(to_string(option.getValue()) + " - " + option.getString());
	io.printNewLine();
    }
}

const OptionMenu MenuText::getOption() {
    string input;
    do {
	io.printMessage("\tEnter an Option: ");
	input = io.getInput();

	for (auto option : menuOptions) {
	    if (to_string(option.getValue()) == input)
		return option;
	}
	
	io.printMessage("Unknown Option\n");
    }while(true);
}
