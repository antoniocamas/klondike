#ifndef SRC_MODEL_MOVEMENTDESCRIBER_H_
#define SRC_MODEL_MOVEMENTDESCRIBER_H_

#include <string>
#include "Card.h"
#include "MovementType.h"

typedef enum {
    ORIGIN,
    DESTINATION,
    ORIGINCARD,
    NONE
}NextMovementElement;

using namespace std;
using namespace card;

class MovementDescriber {
private:
    string origin;
    unsigned int originIndex;
    string destination;
    unsigned int destinatioIndex;
    Card originCard;
    NextMovementElement nextElement;

public:
    MovementDescriber();
    virtual ~MovementDescriber(){};
    
    MovementType getType() const;
    NextMovementElement getNextExpectedElement() const{return nextElement;};

    unsigned int getOriginIndex()const {return originIndex;};
    unsigned int getDestinationIndex()const {return destinatioIndex;};
    Card getOriginCard()const {return originCard;};
    void setOrigin(string, int);
    void setDestination(string, int);
    void setOriginCard(Card);

private:
    void transition2NextMovementElement();
};

#endif /* SRC_MODEL_MOVEMENTDESCRIBER_H_ */
