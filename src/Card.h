/*
 * Card.h
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#ifndef CARD_H_
#define CARD_H_

#include "Suit.h"
#include <string>

using namespace std;

namespace card {

//typedef struct suit
//{
//	string name;
//	string color;
//}st_suit;

class Card {
	int number;
	Suit suit;
	bool upTurned;
public:
	Card(){}
	Card(int number, Suit suit);
	virtual ~Card();
	string card2string();
	inline bool isUpTurned(){return this->upTurned;}
	inline void turn(){this->upTurned = !this->upTurned;}
	inline bool isConsecutiveNumber(Card other){return this->number == other.number-1;}
	inline bool isReverseConsecutiveNumber(Card other){return this->number-1 == other.number;}
	inline bool isSameColor(Card other){return other.suit.isSameColor(this->suit);}
	inline bool isSameSuit(Card other){return other.suit == this->suit;}

};

} /* namespace card */

#endif /* CARD_H_ */
