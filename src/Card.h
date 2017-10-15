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
	Card & operator=(Card other);
	bool operator==(Card otherCard) const;
	bool operator!=(Card otherCard) const {return !((*this) == otherCard);};
	string card2string() const;
	inline const Suit& getSuit() const {return this->suit;}
	inline int  getNumber() const {return this->number;}
	inline bool isUpTurned()const{return this->upTurned;}
	inline void turn(){this->upTurned = !this->upTurned;}
	inline void upTurn(){if(!this->upTurned){this->turn();}}
	inline bool isConsecutiveNumber(Card other){return this->number == other.number-1;}
	inline bool isReverseConsecutiveNumber(Card other){return this->number-1 == other.number;}
	inline bool isSameColor(Card other){return other.suit.isSameColor(this->suit);}
	inline bool isSameSuit(Card other){return other.suit == this->suit;}
	inline bool isFirstNumberOfSuit(){return this->suit.isFirstNumberOfSuit(this->number);}
	inline bool isLastNumberOfSuit(){return this->suit.isLastNumberOfSuit(this->number);}
};

} /* namespace card */

#endif /* CARD_H_ */
