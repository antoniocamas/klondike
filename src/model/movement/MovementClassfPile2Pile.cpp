#include "MovementClassfPile2Pile.h"

MovementClassfPile2Pile::MovementClassfPile2Pile(
    string o, string d, shared_ptr<MovementClassifier> n):
    MovementClassifier(o, d, n) {
};

MovementClassfPile2Pile::MovementClassfPile2Pile(string o, string d):
    MovementClassfPile2Pile(o, d, nullptr) {
}

MovementType MovementClassfPile2Pile::getType() const{
    if (origin == "pile" and destination == "pile") {
	return MovementType::PILE2PILE;
    }

    return this->getTypeNextNode();
}
