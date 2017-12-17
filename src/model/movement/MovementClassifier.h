#ifndef SRC_MODEL_MOVEMENTCLASSIFIER_H_
#define SRC_MODEL_MOVEMENTCLASSIFIER_H_

#include <memory>
#include <string>
#include "MovementType.h"

using namespace std;

class MovementClassifier {
protected:
    string origin;
    string destination;
    shared_ptr<MovementClassifier> next;
public:
    MovementClassifier(string, string, shared_ptr<MovementClassifier>);
    MovementClassifier(string, string);
    virtual ~MovementClassifier(){};
    
    virtual MovementType getType() const = 0;

protected:
    bool hasNext() const;
    MovementType getTypeNextNode() const;
};

#endif /* SRC_MODEL_MOVEMENTCLASSIFIER_H_ */
