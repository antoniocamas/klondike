#include "ViewSaveConsoleLinux.h"

ViewSaveConsoleLinux::ViewSaveConsoleLinux(): io() {
}

string ViewSaveConsoleLinux::getSavingName() {
    clear_screen();
    io.printSplitter();
    io.printMessage("\t\tSaving Name\n");
    io.printSplitter();
    io.printMessage("\tEnter the Name: ");
    return io.getInput();
}
