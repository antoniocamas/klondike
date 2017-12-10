
#include "Option.h"

const Option Option::NEWGAME(1, "New Game");
const Option Option::PLAY(2, "Go back to Play");
const Option Option::UNDO(3, "Undo movement");
const Option Option::REDO(4, "Redo movement");
const Option Option::SAVE(5, "Save Game");
const Option Option::LOAD(6, "Load Game");
const Option Option::QUIT(0, "Quit Klondike");

Option::Option(int val, string nam): value(val), name(nam) {}

int Option::getValue() const{
    return value;
}

const string& Option::getString() const{
    return name;
}
