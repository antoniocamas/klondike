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
	string shortName;
	string color;
	map<int, string> nicknames;

public:
	Suit(){};
	Suit(string name, string color,	int numberOfCardsperSuit, map<int, string> nicknames);
	virtual ~Suit();

	Suit & operator=(Suit other);
	//Suit & operator=(Suit& ) = delete;
	inline bool isSameColor(Suit & other) const {return other.color == this->color;}
	inline bool operator==(Suit & other) const {return other.name == this->name;}
	inline string getColor(){return this->color;}
	inline string getName()const {return this->name;}
	inline string getShortName()const {return this->shortName;}
	string getNickName(int number) const;
	inline bool isFirstNumberOfSuit(int number) const {return number == 1;}
	inline bool isLastNumberOfSuit(int number) const {return number == this->numberOfCardsperSuit;}

};

} /* namespace card */

#endif /* SUIT_H_ */
