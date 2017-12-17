#ifndef SRC_MOVEMENTCONTROLLER_H_
#define SRC_MOVEMENTCONTROLLER_H_

#include "GameCardStack.h"

class MovementController {

protected:
    GameCardStack* origin;
    GameCardStack* destination;

public:
    MovementController(){};
    virtual ~MovementController(){};

    virtual bool isValid() = 0;
    virtual void applyMovement();
};

#endif /* SRC_MOVEMENTCONTROLLER_H_ */
