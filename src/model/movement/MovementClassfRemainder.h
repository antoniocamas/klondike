#ifndef SRC_MODEL_MOVEMENTCLASSFREMAINDER_H_
#define SRC_MODEL_MOVEMENTCLASSFREMAINDER_H_

#include <string>
#include <memory>
#include "MovementType.h"
#include "MovementClassifier.h"

using namespace std;

class MovementClassfRemainder: public MovementClassifier {
public:
    MovementClassfRemainder(string, string, shared_ptr<MovementClassifier>);
    MovementClassfRemainder(string, string);
    virtual ~MovementClassfRemainder(){};
    
    MovementType getType() const;
};

#endif /* SRC_MODEL_MOVEMENTCLASSFREMAINDER_H_ */
