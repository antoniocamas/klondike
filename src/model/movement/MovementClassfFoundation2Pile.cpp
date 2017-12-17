#include "MovementClassfFoundation2Pile.h"

MovementClassfFoundation2Pile::MovementClassfFoundation2Pile(
    string o, string d, shared_ptr<MovementClassifier> n):
    MovementClassifier(o, d, n) {
};

MovementClassfFoundation2Pile::MovementClassfFoundation2Pile(string o, string d):
    MovementClassfFoundation2Pile(o, d, nullptr) {
}

MovementType MovementClassfFoundation2Pile::getType() const{
    if (origin == "foundation" and destination == "pile") {
	return MovementType::FOUNDATION2PILE;
    }

    return this->getTypeNextNode();
}
