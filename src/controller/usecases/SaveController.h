#ifndef SRC_SAVECONTROLLER_H_
#define SRC_SAVECONTROLLER_H_

#include "Controller.h"
#include "TableMarshaller.h"

class SaveController: public Controller {
private:
    TableMarshaller tableMarshaller;
public:
    SaveController(std::shared_ptr<Table> t, std::shared_ptr<View> v);
    virtual ~SaveController(){};
    void control();
    void visit(string);
};

#endif /* SRC_SAVECONTROLLER_H_ */
