#ifndef SRC_UNDOCONTROLLER_H_
#define SRC_UNDOCONTROLLER_H_

#include "Controller.h"
#include "TableRegistry.h"

class UndoController: public Controller {
private:
    std::shared_ptr<TableRegistry> tableRegistry;
public:
    UndoController(std::shared_ptr<Table>, std::shared_ptr<View>,
		   std::shared_ptr<TableRegistry> tr);
    virtual ~UndoController(){};
    void control();
};

#endif /* SRC_UNDOCONTROLLER_H_ */
