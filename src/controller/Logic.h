#ifndef SRC_CONTROLLER_LOGIC_H_
#define SRC_CONTROLLER_LOGIC_H_

#include <memory>
#include "Table.h"
#include "TableRegistry.h"
#include "Controller.h"
#include "View.h"
#include "State.h"

class Logic {
private:
    State state;
    std::shared_ptr<View> view;
    std::shared_ptr<Table> table;
    std::shared_ptr<TableRegistry> tableRegistry;

public:
    Logic(std::shared_ptr<View> v): state(State::NEWGAME),view(v), table(0){
	createNewGame();
    };
    virtual ~Logic(){};

    std::shared_ptr<Controller> getController();
    bool isTimeToExit(){ return (state == State::EXIT);}

private:
    void createNewGame();
};

#endif /* SRC_CONTROLLER_LOGIC_H_ */
