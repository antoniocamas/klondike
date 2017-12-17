#ifndef MENUTEXT_H_
#define MENUTEXT_H_

#include <vector>
#include <string>
#include "IOConsoleLinux.h"
#include "OptionMenu.h"

using namespace std;

class MenuText {

private:
    IOConsoleLinux io;

protected:
    vector<OptionMenu> menuOptions;

public:
    MenuText(vector<OptionMenu>);
    virtual ~MenuText(){};
    void showMenu(string);
    const OptionMenu getOption();
};

#endif /* MENUTEXT_H_ */
