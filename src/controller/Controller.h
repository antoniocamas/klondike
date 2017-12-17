#ifndef SRC_CONTROLLER_CONTROLLER_H_
#define SRC_CONTROLLER_CONTROLLER_H_

#include <memory>
#include "Table.h"
#include "View.h"

class Controller {
protected:
    std::shared_ptr<Table> table;
    std::shared_ptr<View> view;

public:
    Controller(std::shared_ptr<Table> t, std::shared_ptr<View> v): table(t), view(v){};
    virtual ~Controller(){};

    virtual void control() = 0;

};

#endif /* SRC_CONTROLLER_CONTROLLER_H_ */
