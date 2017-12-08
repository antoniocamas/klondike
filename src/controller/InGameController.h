#ifndef SRC_CONTROLLER_INGAMECONTROLLER_H_
#define SRC_CONTROLLER_INGAMECONTROLLER_H_

#include "State.h"
#include "Controller.h"
#include "MovementDescriber.h"
#include "TableRegistry.h"

class InGameController: public Controller {
private:
    State& state;
    MovementDescriber movement;
    TableRegistry* tableRegistry;
public:
    InGameController(Table * t, std::shared_ptr<View> v, State& s, TableRegistry* tr);
    virtual ~InGameController(){};
    void control();
    void visit(MovementDescriber movement);
private:
    void move();
};

#endif /* SRC_CONTROLLER_INGAMECONTROLLER_H_ */
