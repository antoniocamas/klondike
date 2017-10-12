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

//just for debuggin
#include <string>

using namespace std;
namespace card {

class CardStack {
protected:
	vector<Card> cards;

	vector<Card>::iterator findCard(Card card);
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

	//debug funtion
	string cards2string(){
		string repr;
		for (auto card : cards){repr += card.card2string() + "\n\t";} return repr;}

private:
	static int randomGenerator(int i);
};

} /* namespace card */

#endif /* CARDSTACK_H_ */
