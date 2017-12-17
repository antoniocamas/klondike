#ifndef SRC_MODEL_MOVEMENTCLASSFWASTE2FOUNDATION_H_
#define SRC_MODEL_MOVEMENTCLASSFWASTE2FOUNDATION_H_

#include <string>
#include <memory>
#include "MovementType.h"
#include "MovementClassifier.h"

using namespace std;

class MovementClassfWaste2Foundation: public MovementClassifier {
public:
    MovementClassfWaste2Foundation(string, string, shared_ptr<MovementClassifier>);
    MovementClassfWaste2Foundation(string, string);
    virtual ~MovementClassfWaste2Foundation(){};

    MovementType getType() const;
};

#endif /* SRC_MODEL_MOVEMENTCLASSFWASTE2FOUNDATION_H_ */
