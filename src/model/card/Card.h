/*
 * Card.h
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#ifndef CARD_H_
#define CARD_H_

#include <string>
#include "Suit.h"

using namespace std;

namespace card {

class Card {
	unsigned int number;
	Suit suit;
	bool upTurned;
public:
	Card():number(0),upTurned(false){}
	Card(unsigned int number, Suit suit);
	virtual ~Card(){};
	Card & operator=(Card other);
	bool operator==(Card otherCard) const;
	bool operator!=(Card otherCard) const {return !((*this) == otherCard);};
	inline const Suit& getSuit() const {return this->suit;}
	inline unsigned int  getNumber() const {return this->number;}
	inline string getSuitName() const {return this->suit.getName();}
	inline bool isUpTurned()const{return this->upTurned;}
	inline void turn(){this->upTurned = !this->upTurned;}
	inline void upTurn(){if(!this->upTurned){this->turn();}}
	inline bool isConsecutiveNumber(Card other) const {return this->number == other.number-1;}
	inline bool isReverseConsecutiveNumber(Card other) const {return this->number-1 == other.number;}
	inline bool isSameColor(Card other) const{return other.suit.isSameColor(this->suit);}
	inline bool isSameSuit(Card other) const{return other.suit == this->suit;}
	inline bool isFirstNumberOfSuit(){return this->suit.isFirstNumberOfSuit(this->number);}
	inline bool isLastNumberOfSuit() const {return this->suit.isLastNumberOfSuit(this->number);}
	inline bool isEmpty() const{return number == 0;};
};

} /* namespace card */

#endif /* CARD_H_ */
