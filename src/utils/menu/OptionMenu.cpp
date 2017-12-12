#include "OptionMenu.h"

OptionMenu::OptionMenu(int val, string nam): value(val), name(nam) {}

int OptionMenu::getValue() const{
    return value;
}

const string& OptionMenu::getString() const{
    return name;
}
