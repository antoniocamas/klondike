#ifndef SRC_SAVECONTROLLER_H_
#define SRC_SAVECONTROLLER_H_

#include "Controller.h"

class SaveController: public Controller {
private:
public:
    SaveController(Table * t, std::shared_ptr<View> v);
    virtual ~SaveController(){};
    void control();
};

#endif /* SRC_SAVECONTROLLER_H_ */
