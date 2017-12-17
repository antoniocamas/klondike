#ifndef SRC_VIEW_VIEW_H_
#define SRC_VIEW_VIEW_H_

#include "Table.h"

class MenuController;
class InGameController;
class LoadController;
class SaveController;
class WinGameController;

class View {
protected:
    Table * table;
public:

    virtual void setTable(Table *t) = 0;
    virtual void accept(MenuController* controller) = 0;
    virtual void accept(InGameController* controller) = 0;
    virtual void accept(LoadController* controller) = 0;
    virtual void accept(SaveController* controller) = 0;
    virtual void accept(WinGameController* controller) = 0;
};

#endif /* SRC_VIEW_VIEW_H_ */
