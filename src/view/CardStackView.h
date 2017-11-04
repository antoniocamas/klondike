/*
 * CardStackRepresenter.h
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#ifndef SRC_VIEW_CARDSTACKVIEW_H_
#define SRC_VIEW_CARDSTACKVIEW_H_

#include <vector>
#include <string>

#include "Card.h"

namespace card {

class CardStackView {
private:
	vector<Card>::const_iterator beginIt;
	vector<Card>::const_iterator endIt;
protected:
	virtual string representCard(Card card);
public:
	CardStackView(){};
	CardStackView(vector<Card>::const_iterator b,
			vector<Card>::const_iterator e): beginIt(b), endIt(e) {};
	virtual ~CardStackView();
	CardStackView& operator=(CardStackView other);

	vector<string> upTurnedCards2String();
	string topCard2String();
	vector<string> topCard2String(int numberOfCards);
	vector<string> allCard2String();
	int getNumberOfCardsInTheStack();
};

} /* namespace card */

#endif /* SRC_VIEW_CARDSTACKVIEW_H_ */
