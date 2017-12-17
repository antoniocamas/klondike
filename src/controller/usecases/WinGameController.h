#ifndef SRC_CONTROLLER_WINGAMECONTROLLER_H_
#define SRC_CONTROLLER_WINGAMECONTROLLER_H_

#include "Controller.h"

class WinGameController: public Controller {
public:
    WinGameController(std::shared_ptr<Table>, std::shared_ptr<View> v);
    virtual ~WinGameController(){};
    void control();
};

#endif /* SRC_CONTROLLER_WINGAMECONTROLLER_H_ */
