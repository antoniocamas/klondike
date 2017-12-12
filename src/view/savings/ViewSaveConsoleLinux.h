#ifndef VIEWSAVECONSOLELINUX_H_
#define VIEWSAVECONSOLELINUX_H_

#include <memory>
#include "IOConsoleLinux.h"

using namespace std;

class ViewSaveConsoleLinux {

private:
    IOConsoleLinux io;
public:
    ViewSaveConsoleLinux();
    virtual ~ViewSaveConsoleLinux(){};
    string getSavingName();
};

#endif /* VIEWSAVECONSOLELINUX_H_ */
