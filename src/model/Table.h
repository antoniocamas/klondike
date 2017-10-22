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
#include <string>
#include "Score.h"
#include "../CardStackRepresenter.h"
#include "Pile.h"
#include "Foundation.h"
#include "CardStack.h"
#include "Deck.h"

using namespace std;

//typedef enum {
//	remainder,
//	waste,
//	pile,
//	foundation
//}TableauArea;

const int numberOfFoundations = 4;
const int numberOfPiles = 7;

class Table {
private:

	Score score;
	array<Pile,numberOfPiles> piles;
	array<Foundation,numberOfFoundations> foundations;
	CardStack remainder;
	CardStack waste;

	void deal();

public:
	Table();
	virtual ~Table();

	bool areAllFoundationsComplete() const;
	inline int getNumberOfPiles() const {return piles.size();}
	inline int getNumberOfFundations() const {return foundations.size();}
	CardStackRepresenter getRemainderRepresenter() const {return this->remainder.getCardsRepresenter();}
	CardStackRepresenter getWasterRepresenter() const {return this->waste.getCardsRepresenter();}
	CardStackRepresenter getFoundationRepresenter(int foundationNumber) const {return this->foundations.at(foundationNumber).getCardsRepresenter();}
	CardStackRepresenter getPileRepresenter(int pileNumber) const {return this->piles.at(pileNumber).getCardsRepresenter();}

	CardStack* getRemainder(){return &this->remainder;}
	CardStack* getWaste(){return &this->waste;}
	Pile* getPile(int pileNumber){return &this->piles[pileNumber];}
	Foundation* getFoundation(int foundationNumber){return &this->foundations[foundationNumber];}
};


#endif /* TABLEAU_H_ */
