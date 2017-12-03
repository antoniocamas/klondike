#ifndef SRC_CONTROLLER_MOVEMENT_FOUNDATION2PILECONTROLLER_H_
#define SRC_CONTROLLER_MOVEMENT_FOUNDATION2PILECONTROLLER_H_

#include "Table.h"
#include "OneCardMovementController.h"

class Foundation2PileController: public OneCardMovementController {
public:
    Foundation2PileController(Table * t, int oriFoundation, int destPile);
    virtual ~Foundation2PileController(){};
};

#endif /* SRC_CONTROLLER_MOVEMENT_FOUNDATION2PILECONTROLLER_H_ */
