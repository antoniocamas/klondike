#ifndef SRC_REDOCONTROLLER_H_
#define SRC_REDOCONTROLLER_H_

#include "Controller.h"
#include "TableRegistry.h"

class RedoController: public Controller {
private:
    TableRegistry* tableRegistry;
public:
    RedoController(Table * t, std::shared_ptr<View> v, TableRegistry* tr);
    virtual ~RedoController(){};
    void control();
};

#endif /* SRC_REDOCONTROLLER_H_ */
