/*
 * CardStackRepresenter.h
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#ifndef SRC_CARDSTACKREPRESENTER_H_
#define SRC_CARDSTACKREPRESENTER_H_

#include <vector>
#include <string>

#include "Card.h"

namespace card {

class CardStackRepresenter {
private:
	vector<Card>::const_iterator beginIt;
	vector<Card>::const_iterator endIt;
protected:
	virtual string representCard(Card card) const;
public:
	CardStackRepresenter(){};
	CardStackRepresenter(vector<Card>::const_iterator b, vector<Card>::const_iterator e): beginIt(b), endIt(e) {}
	virtual ~CardStackRepresenter();
	CardStackRepresenter& operator=(CardStackRepresenter other);

	vector<string> upTurnedCards2String();
	string topCard2String();
	vector<string> topCard2String(int numberOfCards);
	vector<string> allCard2String();
	int getNumberOfCardsInTheStack();
};

} /* namespace card */

#endif /* SRC_CARDSTACKREPRESENTER_H_ */
