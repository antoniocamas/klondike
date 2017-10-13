/*
 * TableLayout.h
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#ifndef TABLEAU_H_
#define TABLEAU_H_

#include <vector>
#include <array>
#include "Score.h"
#include "CardStack.h"
#include "Pile.h"
#include "Foundation.h"

using namespace std;

class Tableau {
private:

	Score score;
	array<Pile,7> piles;
	array<Foundation,4> foundations;
	CardStack remainder;
	CardStack waste;

	void deal();

public:
	Tableau();
	int getPileSize(){return piles.size();}
	vector<Card>::const_iterator remainderCbegin(){return this->remainder.cbegin();}
	vector<Card>::const_iterator remainderCend(){return this->remainder.cend();}
	vector<Card>::const_iterator pileCbegin(int index){return this->piles.at(index).cbegin();}
	vector<Card>::const_iterator pileCend(int index){return this->piles.at(index).cend();}
	virtual ~Tableau();
};


#endif /* TABLEAU_H_ */
