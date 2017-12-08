
#include "Option.h"

const Option Option::NEWGAME(1, "New Game");
const Option Option::PLAY(2, "Go back to Play");
const Option Option::QUIT(3, "Quit Klondike");

Option::Option(int val, string nam): value(val), name(nam) {}

int Option::getValue() const{
    return value;
}

const string& Option::getString() const{
    return name;
}
