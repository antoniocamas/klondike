#include <iostream>
#include <cstdlib>
#include "StringHandler.h"
#include "IOConsoleLinux.h"

using namespace std;

void IOConsoleLinux::printNewLine() {
    cout << endl;
}

void IOConsoleLinux::printMessage(string message) {
    cout << message;
}

void IOConsoleLinux::printSplitter() {
    cout << string(80, '-') << endl;
}

string IOConsoleLinux::getInput() {
    string input;
    cin >> input;
    StringHandler stringHandler(input);
    stringHandler.lowercase();
    return stringHandler.getString();
}

void clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}
