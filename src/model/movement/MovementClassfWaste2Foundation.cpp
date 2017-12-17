#include "MovementClassfWaste2Foundation.h"

MovementClassfWaste2Foundation::MovementClassfWaste2Foundation(
    string o, string d, shared_ptr<MovementClassifier> n):
    MovementClassifier(o, d, n) {
};

MovementClassfWaste2Foundation::MovementClassfWaste2Foundation(string o, string d):
    MovementClassfWaste2Foundation(o, d, nullptr) {
}

MovementType MovementClassfWaste2Foundation::getType() const{
    if (origin == "waste" and destination == "foundation") {
	return MovementType::WASTE2FOUNDATION;
    }

    return this->getTypeNextNode();
}
