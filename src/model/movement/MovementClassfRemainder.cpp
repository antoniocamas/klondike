#include "MovementClassfRemainder.h"

MovementClassfRemainder::MovementClassfRemainder(
    string o, string d, shared_ptr<MovementClassifier> n):
    MovementClassifier(o, d, n) {
};

MovementClassfRemainder::MovementClassfRemainder(string o, string d):
    MovementClassfRemainder(o, d, nullptr) {
}

MovementType MovementClassfRemainder::getType() const{
    if (origin.empty()) {
	return MovementType::NOTAMOVEMENT;
    }
    else if (origin == "remainder") {
	return MovementType::REMAINDER2WASTE;
    }

    return this->getTypeNextNode();
}
