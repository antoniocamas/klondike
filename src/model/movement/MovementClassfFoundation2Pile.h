#ifndef SRC_MODEL_MOVEMENTCLASSFFOUNDATION2PILE_H_
#define SRC_MODEL_MOVEMENTCLASSFFOUNDATION2PILE_H_

#include <string>
#include <memory>
#include "MovementType.h"
#include "MovementClassifier.h"

using namespace std;

class MovementClassfFoundation2Pile: public MovementClassifier {
public:
    MovementClassfFoundation2Pile(string, string, shared_ptr<MovementClassifier>);
    MovementClassfFoundation2Pile(string, string);
    virtual ~MovementClassfFoundation2Pile(){};

    MovementType getType() const;
};

#endif /* SRC_MODEL_MOVEMENTCLASSFFOUNDATION2PILE_H_ */
