#ifndef VIEWMENUCONSOLELINUX_H_
#define VIEWMENUCONSOLELINUX_H_

#include <vector>
#include <string>
#include "IOConsoleLinux.h"

using namespace std;

class ViewMenuConsoleLinux {

private:
    IOConsoleLinux io;

public:
    ViewMenuConsoleLinux(){};
    virtual ~ViewMenuConsoleLinux(){};
    void showMenu();
};

#endif /* VIEWMENUCONSOLELINUX_H_ */
