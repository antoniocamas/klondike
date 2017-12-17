#ifndef SRC_MODEL_GAMECARDSTACK_H_
#define SRC_MODEL_GAMECARDSTACK_H_

#include "Card.h"
#include "CardStack.h"

class GameCardStack: public card::CardStack {
public:
    GameCardStack(){};
    virtual ~GameCardStack(){};

    virtual bool isPuttingDownPossible(card::Card)const {return true;};
    virtual bool isMovingTopStackPossible(card::Card){return false;};
};

#endif /* SRC_MODEL_GAMECARDSTACK_H_ */
