#ifndef SRC_VIEWCONSOLELINUX_H_
#define SRC_VIEWCONSOLELINUX_H_

#include "MenuController.h"
#include "InGameController.h"
#include "LoadController.h"
#include "SaveController.h"

class ViewConsoleLinux: public View {
protected:
    Table * table;
public:
    ViewConsoleLinux(){};
    virtual ~ViewConsoleLinux(){};
    
    void setTable(Table *t){table = t;};
    void accept(MenuController* controller);
    void accept(InGameController* controller);
    void accept(LoadController* controller);
    void accept(SaveController* controller);
};

#endif /* SRC_VIEWCONSOLELINUX_H_ */
