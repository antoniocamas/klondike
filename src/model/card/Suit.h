/*
 * Suit.h
 *
 *  Created on: Oct 8, 2017
 *      Author: antonio
 */

#ifndef SUIT_H_
#define SUIT_H_

#include <iostream>
#include <string>

using namespace std;

namespace card {

class Suit {
private:
	int numberOfCardsperSuit;
	string name;
	string color;

public:
	Suit():numberOfCardsperSuit(0){};
	Suit(string name, string color,	int numberOfCardsperSuit);
	virtual ~Suit(){};

	Suit & operator=(Suit other);
	//Suit & operator=(Suit& ) = delete;
	inline bool isSameColor(const Suit& other) const {return other.color == this->color;}
	inline bool operator==(const Suit & other) const {return other.name == this->name;}
	inline string getColor(){return this->color;}
	inline string getName()const {return this->name;}
	inline bool isFirstNumberOfSuit(int number) const {return number == 1;}
	inline bool isLastNumberOfSuit(int number) const {return number == this->numberOfCardsperSuit;}

};

} /* namespace card */

#endif /* SUIT_H_ */
