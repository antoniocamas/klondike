#ifndef SRC_MODEL_MOVEMENTCLASSFPILE2PILE_H_
#define SRC_MODEL_MOVEMENTCLASSFPILE2PILE_H_

#include <string>
#include <memory>
#include "MovementType.h"
#include "MovementClassifier.h"

using namespace std;

class MovementClassfPile2Pile: public MovementClassifier {
public:
    MovementClassfPile2Pile(string, string, shared_ptr<MovementClassifier>);
    MovementClassfPile2Pile(string, string);
    virtual ~MovementClassfPile2Pile(){};

    MovementType getType() const;
};

#endif /* SRC_MODEL_MOVEMENTCLASSFPILE2PILE_H_ */
