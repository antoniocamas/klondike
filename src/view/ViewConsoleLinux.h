#ifndef SRC_VIEWCONSOLELINUX_H_
#define SRC_VIEWCONSOLELINUX_H_

//#include <memory>
//#include "Table.h"
//#include "MovementDescriber.h"
#include "MenuController.h"
#include "InGameController.h"

class ViewConsoleLinux: public View {
protected:
    Table * table;
public:
    ViewConsoleLinux(){};
    virtual ~ViewConsoleLinux(){};
    
    void setTable(Table *t){table = t;};
    void accept(MenuController* controller);
    void accept(InGameController* controller);
};

#endif /* SRC_VIEWCONSOLELINUX_H_ */
