#ifndef SRC_MODEL_MOVEMENTCLASSFPILE2FOUNDATION_H_
#define SRC_MODEL_MOVEMENTCLASSFPILE2FOUNDATION_H_

#include <string>
#include <memory>
#include "MovementType.h"
#include "MovementClassifier.h"

using namespace std;

class MovementClassfPile2Foundation: public MovementClassifier {
public:
    MovementClassfPile2Foundation(string, string, shared_ptr<MovementClassifier>);
    MovementClassfPile2Foundation(string, string);
    virtual ~MovementClassfPile2Foundation(){};
    
    MovementType getType() const;
};

#endif /* SRC_MODEL_MOVEMENTCLASSFPILE2FOUNDATION_H_ */
