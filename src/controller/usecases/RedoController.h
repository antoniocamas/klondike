#ifndef SRC_REDOCONTROLLER_H_
#define SRC_REDOCONTROLLER_H_

#include "Controller.h"
#include "TableRegistry.h"

class RedoController: public Controller {
private:
    std::shared_ptr<TableRegistry> tableRegistry;
public:
    RedoController(std::shared_ptr<Table>, std::shared_ptr<View>,
		   std::shared_ptr<TableRegistry>);
    virtual ~RedoController(){};
    void control();
};

#endif /* SRC_REDOCONTROLLER_H_ */
