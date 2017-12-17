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
    std::shared_ptr<TableRegistry> tableRegistry;
public:
    InGameController(std::shared_ptr<Table>, std::shared_ptr<View>,
		     State&, std::shared_ptr<TableRegistry>);
    virtual ~InGameController(){};
    void control();
    void visit(MovementDescriber movement);
private:
    void move();
};

#endif /* SRC_CONTROLLER_INGAMECONTROLLER_H_ */
