#ifndef SRC_MODEL_MOVEMENTCLASSIFIERBUILDER_H_
#define SRC_MODEL_MOVEMENTCLASSIFIERBUILDER_H_

#include <string>
#include <memory>
#include "MovementClassifier.h"

using namespace std;

class MovementClassifierBuilder {
public:
    MovementClassifierBuilder(){};
    virtual ~MovementClassifierBuilder(){};
    
    shared_ptr<MovementClassifier> getMovementClassifer(string, string);
};

#endif /* SRC_MODEL_MOVEMENTCLASSIFIERBUILDER_H_ */
