#ifndef FOUNDATION_H_
#define FOUNDATION_H_

#include "Card.h"
#include "Pile.h"

class Foundation: public Pile {
public:
    Foundation(){};
    virtual ~Foundation(){};
    bool isComplete() const;
    bool isPuttingDownPossible(card::Card inCommingCard) const;
};

#endif /* FOUNDATION_H_ */
