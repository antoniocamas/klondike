#ifndef SRC_CONTROLLER_MOVEMENT_WASTE2PILECONTROLLER_H_
#define SRC_CONTROLLER_MOVEMENT_WASTE2PILECONTROLLER_H_

#include "Table.h"
#include "OneCardMovementController.h"

class Waste2PileController: public OneCardMovementController {
public:
    Waste2PileController(Table * t, int p);
    virtual ~Waste2PileController(){};
};

#endif /* SRC_CONTROLLER_MOVEMENT_WASTE2PILECONTROLLER_H_ */
