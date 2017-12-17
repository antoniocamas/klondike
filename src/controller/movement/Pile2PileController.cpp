#include <vector>
#include "Pile2PileController.h"

Pile2PileController::Pile2PileController(
    Table * table, int originPileNumber, int destinationPileNumber,
    Card originCard): originCard(originCard) {

    this->origin = &(*table->getPile(originPileNumber));
    this->destination = &(*table->getPile(destinationPileNumber));
}

void Pile2PileController::applyMovement() {
    vector<Card> cards = origin->giveTopCardAway(origin->numberOfCardsOnTopOf(originCard));
    origin->turnTopCard();
    destination->putCardOnTop(cards);
}

bool Pile2PileController::isValid() {

    if (origin->isMovingTopStackPossible(originCard) and
	destination->isPuttingDownPossible(originCard))
	return true;
    return false;
}
