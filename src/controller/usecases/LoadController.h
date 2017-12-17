#ifndef SRC_LOADCONTROLLER_H_
#define SRC_LOADCONTROLLER_H_

#include <vector>
#include <string>
#include "Controller.h"
#include "TableRegistry.h"
#include "TableMarshaller.h"

class LoadController: public Controller {
private:
    std::shared_ptr<TableRegistry> tableRegistry;
    TableMarshaller tableMarshaller;
public:
    LoadController(std::shared_ptr<Table>, std::shared_ptr<View>,  std::shared_ptr<TableRegistry>);
    virtual ~LoadController(){};
    void control();
    void visit(string);
    vector<string> getSavedGames();
};

#endif /* SRC_LOADCONTROLLER_H_ */
