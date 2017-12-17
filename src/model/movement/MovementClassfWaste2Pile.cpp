#include "MovementClassfWaste2Pile.h"

MovementClassfWaste2Pile::MovementClassfWaste2Pile(
    string o, string d, shared_ptr<MovementClassifier> n):
    MovementClassifier(o, d, n) {
};

MovementClassfWaste2Pile::MovementClassfWaste2Pile(string o, string d):
    MovementClassfWaste2Pile(o, d, nullptr) {
}

MovementType MovementClassfWaste2Pile::getType() const{
    if (origin == "waste" and destination == "pile") {
	return MovementType::WASTE2PILE;
    }

    return this->getTypeNextNode();
}
