#include "MovementClassifier.h"

MovementClassifier::MovementClassifier(string o, string d, shared_ptr<MovementClassifier> n):
    origin(o), destination(d), next(n) {
};

MovementClassifier::MovementClassifier(string o, string d):
    MovementClassifier(o, d, nullptr) {
}

bool MovementClassifier::hasNext() const {
    return next != nullptr;
}

MovementType MovementClassifier::getTypeNextNode() const {
    if (hasNext()) {
	return next->getType();
    }

    return MovementType::NOTALLOWED;
}
