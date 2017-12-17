#ifndef SRC_CONTROLLER_LOGIC_H_
#define SRC_CONTROLLER_LOGIC_H_

#include <memory>
#include "State.h"
#include "Table.h"
#include "TableRegistry.h"
#include "Controller.h"
#include "View.h"

class Logic {
private:
    State state;
    std::shared_ptr<View> view;
    std::shared_ptr<Table> table;
    std::shared_ptr<TableRegistry> tableRegistry;

public:
    Logic(std::shared_ptr<View> v);
    virtual ~Logic(){};

    std::shared_ptr<Controller> getController();
    bool isTimeToExit();

private:
    void createNewGame();
};

#endif /* SRC_CONTROLLER_LOGIC_H_ */
