#ifndef SRC_MODEL_MOVEMENTCLASSFWASTE2PILE_H_
#define SRC_MODEL_MOVEMENTCLASSFWASTE2PILE_H_

#include <string>
#include <memory>
#include "MovementType.h"
#include "MovementClassifier.h"

using namespace std;

class MovementClassfWaste2Pile: public MovementClassifier {
public:
    MovementClassfWaste2Pile(string, string, shared_ptr<MovementClassifier>);
    MovementClassfWaste2Pile(string, string);
    virtual ~MovementClassfWaste2Pile(){};
    
    MovementType getType() const;
};

#endif /* SRC_MODEL_MOVEMENTCLASSFWASTE2PILE_H_ */
