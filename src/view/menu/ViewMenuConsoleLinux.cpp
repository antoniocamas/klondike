
#include <string>
#include "ViewMenuConsoleLinux.h"

void ViewMenuConsoleLinux::showMenu() {
    clear_screen();
    io.printSplitter();
    io.printMessage("\t\t Klondike Menu\n");
    io.printSplitter();

    for (auto line : menuOptions) {
	io.printMessage(std::to_string(line.getValue()) + " - " + line.getString());
	io.printNewLine();
    }
}

const Option ViewMenuConsoleLinux::getOption() {
    string input;
    do {
	io.printMessage("\tEnter and Option: ");
	input = io.getInput();
	
	for (auto option : menuOptions) {
	    if (std::to_string(option.getValue()) == input)
		return option;
	}

	io.printMessage("Unknown Option\n");
    }while(true);
}
