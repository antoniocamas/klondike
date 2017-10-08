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
	string name;
	string color;
public:
	Suit(){};
	Suit(string name, string color);
	virtual ~Suit();

	Suit & operator=(Suit other);
	//Suit & operator=(Suit& ) = delete;
	inline bool isSameColor(Suit & other){return other.color == this->color;}
	inline bool operator==(Suit & other) {return other.name == this->name;}
	inline string getColor(){return this->color;}
	inline string getName(){return this->name;}
};

} /* namespace card */

#endif /* SUIT_H_ */
