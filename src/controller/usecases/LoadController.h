#ifndef SRC_LOADCONTROLLER_H_
#define SRC_LOADCONTROLLER_H_

#include "Controller.h"
#include "TableRegistry.h"

class LoadController: public Controller {
private:
    TableRegistry* tableRegistry;
public:
    LoadController(Table * t, std::shared_ptr<View> v,  TableRegistry* tr);
    virtual ~LoadController(){};
    void control();
};

#endif /* SRC_LOADCONTROLLER_H_ */
