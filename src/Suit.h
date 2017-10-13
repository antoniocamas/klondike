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
#include <map>

using namespace std;

namespace card {

class Suit {
private:
	int numberOfCardsperSuit;
	string name;
	string color;
	map<int, string> nicknames;

public:
	Suit(){};
	Suit(string name, string color,	int numberOfCardsperSuit, map<int, string> nicknames);
	virtual ~Suit();

	Suit & operator=(Suit other);
	//Suit & operator=(Suit& ) = delete;
	inline bool isSameColor(Suit & other){return other.color == this->color;}
	inline bool operator==(Suit & other) {return other.name == this->name;}
	inline string getColor(){return this->color;}
	inline string getName()const {return this->name;}
	string getNickName(int number) const;
	inline bool isFirstNumberOfSuit(int number){return number == 1;}
	inline bool isLastNumberOfSuit(int number){return number == this->numberOfCardsperSuit;}

};

} /* namespace card */

#endif /* SUIT_H_ */
