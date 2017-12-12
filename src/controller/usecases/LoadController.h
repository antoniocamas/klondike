#ifndef SRC_LOADCONTROLLER_H_
#define SRC_LOADCONTROLLER_H_

#include <vector>
#include <string>
#include "Controller.h"
#include "TableRegistry.h"
#include "TableMarshaller.h"

class LoadController: public Controller {
private:
    TableRegistry* tableRegistry;
    TableMarshaller tableMarshaller;
public:
    LoadController(Table * t, std::shared_ptr<View> v,  TableRegistry* tr);
    virtual ~LoadController(){};
    void control();
    void visit(string);
    vector<string> getSavedGames();
};

#endif /* SRC_LOADCONTROLLER_H_ */
