#ifndef SRC_CONTROLLER_MENUCONTROLLER_H_
#define SRC_CONTROLLER_MENUCONTROLLER_H_

#include "State.h"
#include "Controller.h"
#include "Option.h"

class MenuController: public Controller {
private:
    State& state;
public:
    MenuController(Table * t, std::shared_ptr<View> v, State& s): Controller(t, v),state(s){};
    virtual ~MenuController(){};
    void control();
    void visit(Option op);
};

#endif /* SRC_CONTROLLER_MENUCONTROLLER_H_ */
