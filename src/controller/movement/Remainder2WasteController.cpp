#include "Remainder2WasteController.h"

Remainder2WasteController::Remainder2WasteController(Table * table){
	this->destination = table->getWaste();
	this->origin = table->getRemainder();
};

void Remainder2WasteController::applyMovement() {
	if (!this->origin->isEmpty()){
		MovementController::applyMovement();
	}
	else{
		vector<Card> cardsWaste = destination->giveTopCardAway(destination->getNumberOfCards());
		vector<Card> cards4Remainder;
		for (auto card :cardsWaste)
			cards4Remainder.insert(cards4Remainder.begin(), card);
		origin->putCardOnTop(cards4Remainder);
	}
}

bool Remainder2WasteController::isValid() {
	return !this->origin->isEmpty() or !this->destination->isEmpty();
}
