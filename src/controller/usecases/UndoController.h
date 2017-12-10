#ifndef SRC_UNDOCONTROLLER_H_
#define SRC_UNDOCONTROLLER_H_

#include "Controller.h"
#include "TableRegistry.h"

class UndoController: public Controller {
private:
    TableRegistry* tableRegistry;
public:
    UndoController(Table * t, std::shared_ptr<View> v, TableRegistry* tr);
    virtual ~UndoController(){};
    void control();
};

#endif /* SRC_UNDOCONTROLLER_H_ */
