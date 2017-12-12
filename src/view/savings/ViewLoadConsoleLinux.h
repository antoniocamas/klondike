#ifndef VIEWLOADCONSOLELINUX_H_
#define VIEWLOADCONSOLELINUX_H_

#include <memory>
#include "MenuText.h"

using namespace std;

class ViewLoadConsoleLinux {

private:
    shared_ptr<MenuText> menu;

public:
    ViewLoadConsoleLinux(vector<string>);
    virtual ~ViewLoadConsoleLinux(){};
    void showSavedGames();
    string getSavingName();
};

#endif /* VIEWLOADCONSOLELINUX_H_ */
