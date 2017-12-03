#ifndef SRC_CONTROLLER_MOVEMENT_REMAINDER2WASTECONTROLLER_H_
#define SRC_CONTROLLER_MOVEMENT_REMAINDER2WASTECONTROLLER_H_

#include "MovementController.h"
#include "Table.h"

class Remainder2WasteController: public MovementController {
public:
    Remainder2WasteController(Table * t);
    virtual ~Remainder2WasteController(){};

    void applyMovement();
    bool isValid();
};

#endif /* SRC_CONTROLLER_MOVEMENT_REMAINDER2WASTECONTROLLER_H_ */
