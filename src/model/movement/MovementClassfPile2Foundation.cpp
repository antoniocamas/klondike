#include "MovementClassfPile2Foundation.h"

MovementClassfPile2Foundation::MovementClassfPile2Foundation(
    string o, string d, shared_ptr<MovementClassifier> n):
    MovementClassifier(o, d, n) {
};

MovementClassfPile2Foundation::MovementClassfPile2Foundation(string o, string d):
    MovementClassfPile2Foundation(o, d, nullptr) {
}

MovementType MovementClassfPile2Foundation::getType() const{
    if (origin == "pile" and destination == "foundation") {
	return MovementType::PILE22FOUNDATION;
    }

    return this->getTypeNextNode();
}
