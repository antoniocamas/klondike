/*
 * CardStack.h
 *
 *  Created on: Oct 8, 2017
 *      Author: antonio
 */

#ifndef CARDSTACK_H_
#define CARDSTACK_H_

#include <vector>
#include "Card.h"

using namespace std;
namespace card {

class CardStack {
protected:
	vector<Card> cards;

public:
	CardStack(){};
	virtual ~CardStack();
	bool isEmpty(){return cards.empty();}
	size_t getNumberOfCards(){return this->cards.size(); }
	void putCardOnTop(Card card){ this->cards.push_back(card);}
	void putCardOnTop(vector<Card> otherCards);
	Card giveTopCardAway();
	vector<Card> giveTopCardAway(int numberOfCards);
	vector<Card> getUpTurnedCards();
	void shuffle();

private:
	static int randomGenerator(int i);
};

} /* namespace card */

#endif /* CARDSTACK_H_ */
