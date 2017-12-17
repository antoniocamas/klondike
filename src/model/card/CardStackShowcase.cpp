#include <vector>
#include "Card.h"
#include "CardStackShowcase.h"

using namespace std;

namespace card {

CardStackShowcase& CardStackShowcase::operator =(
    CardStackShowcase other) {
    this->beginIt = other.beginIt;
    this->endIt = other.endIt;
    return *this;
}

int CardStackShowcase::getNumberOfCardsInTheStack() const {
    return distance(this->beginIt, this->endIt);
}

vector<const Card*> CardStackShowcase::all() const {
    return this->top(this->getNumberOfCardsInTheStack());
}

vector<const Card*> CardStackShowcase::top(int numberOfCards) const {
    vector<const Card*> cardReferences;
    vector<Card>::const_iterator firstCardIt;

    if (numberOfCards > this->getNumberOfCardsInTheStack())
	firstCardIt = this->beginIt;
    else
	firstCardIt = this->endIt - numberOfCards;

    for (vector<Card>::const_iterator it = firstCardIt; it != this->endIt; ++it){
	cardReferences.push_back(&it[0]);
    }

    return cardReferences;
}

} /* namespace card */
