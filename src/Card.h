/*
 * Card.h
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#ifndef CARD_H_
#define CARD_H_

#include <string>

using namespace std;

typedef struct suit
{
	string name;
	string color;
}st_suit;

class Card {
	int number;
	st_suit suit;
public:
	Card() {number = 0; suit.name=""; suit.color="";};
	string card2string(){return to_string(number) + ", " + suit.name;};
	Card(int n, st_suit s);

	virtual ~Card();
};

#endif /* CARD_H_ */
