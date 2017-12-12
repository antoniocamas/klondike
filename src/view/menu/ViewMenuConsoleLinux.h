#ifndef VIEWMENUCONSOLELINUX_H_
#define VIEWMENUCONSOLELINUX_H_

#include <memory>
#include "OptionMenu.h"
#include "MenuText.h"

using namespace std;

class ViewMenuConsoleLinux {

private:
    shared_ptr<MenuText> menu;

public:
    ViewMenuConsoleLinux();
    virtual ~ViewMenuConsoleLinux();
    void showMenu();
    const OptionMenu getOption();
};

#endif /* VIEWMENUCONSOLELINUX_H_ */
