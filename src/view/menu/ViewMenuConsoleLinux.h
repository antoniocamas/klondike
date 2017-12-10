#ifndef VIEWMENUCONSOLELINUX_H_
#define VIEWMENUCONSOLELINUX_H_

#include <vector>
#include <string>
#include "IOConsoleLinux.h"
#include "Option.h"

using namespace std;

class ViewMenuConsoleLinux {

private:
    IOConsoleLinux io;

    vector<Option> menuOptions = {
	Option::NEWGAME,
	Option::PLAY,
	Option::UNDO,
	Option::REDO,
	Option::SAVE,
	Option::LOAD,
	Option::QUIT
    };

public:
    ViewMenuConsoleLinux(){};
    virtual ~ViewMenuConsoleLinux(){};
    void showMenu();
    const Option getOption();
};

#endif /* VIEWMENUCONSOLELINUX_H_ */
