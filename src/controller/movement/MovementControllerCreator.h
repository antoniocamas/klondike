#ifndef SRC_CONTROLLER_MOVEMENT_MOVEMENTCONTROLLERCREATOR_H_
#define SRC_CONTROLLER_MOVEMENT_MOVEMENTCONTROLLERCREATOR_H_

#include <memory>
#include "Table.h"
#include "MovementController.h"
#include "MovementDescriber.h"

using namespace std;

class MovementControllerCreator {
private:
    Table* table;
    MovementDescriber movementDescriber;

public:
    MovementControllerCreator(Table*, MovementDescriber);
    virtual ~MovementControllerCreator(){};

    shared_ptr<MovementController> getMovement() const;
};

#endif /* SRC_CONTROLLER_MOVEMENT_MOVEMENTCONTROLLERCREATOR_H_ */
