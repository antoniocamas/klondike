#include <vector>
#include "Pile.h"

using namespace std;
using namespace card;

vector<Card> Pile::giveTopCardAway(Card fistCard2Lift) {
    vector<Card> cards2Return;
    vector<Card>::iterator it = this->findCard(fistCard2Lift);

    cards2Return.assign(it, this->cards.end());
    this->cards.resize(distance(this->cards.begin(), it));

    return cards2Return;
}

bool Pile::isPuttingDownPossible(Card inCommingCard) const{
    if (this->cards.empty())
	return inCommingCard.isLastNumberOfSuit();

    return this->cards.back().isReverseConsecutiveNumber(inCommingCard) and
	!(this->cards.back().isSameColor(inCommingCard));
}

bool Pile::isMovingTopStackPossible(Card card) {
    vector<Card>::iterator foundCardIt = this->findCard(card);

    if (foundCardIt == cards.end())
	return false;

    for (auto it = foundCardIt; it!= cards.end()-1; ++it)
	if (!(*it).isReverseConsecutiveNumber(*(it+1)) or (*it).isSameColor(*(it+1)) or
	    (*it).isSameSuit(*(it+1)))
	    return false;
    return true;
}
