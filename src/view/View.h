#ifndef SRC_VIEW_VIEW_H_
#define SRC_VIEW_VIEW_H_

#include "Table.h"

class MenuController;
class InGameController;

class View {
protected:
    Table * table;
public:
    
    virtual void setTable(Table *t) = 0;
    virtual void accept(MenuController* controller) = 0;
    virtual void accept(InGameController* controller) = 0;

    
    // virtual void showTable() = 0;
    // virtual void showWinMessage() = 0;
    // virtual MovementDescriber getNextMovement() = 0;
};

#endif /* SRC_VIEW_VIEW_H_ */
