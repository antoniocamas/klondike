/*
 * CardStackShowcase.h
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#ifndef SRC_MODEL_CARD_CARDSTACKSHOWCASE_H_
#define SRC_MODEL_CARD_CARDSTACKSHOWCASE_H_

#include <vector>
#include "Card.h"

namespace card {

class CardStackShowcase {
private:
	vector<Card>::const_iterator beginIt;
	vector<Card>::const_iterator endIt;
public:
	CardStackShowcase(){};
	CardStackShowcase(vector<Card>::const_iterator b,
		vector<Card>::const_iterator e): beginIt(b), endIt(e) {};
	virtual ~CardStackShowcase(){};

	CardStackShowcase& operator=(CardStackShowcase other);
	int getNumberOfCardsInTheStack() const;
	vector<const Card*> top(int numberOfCards) const;
	vector<const Card*> all() const;
};

} /* namespace card */

#endif /* SRC_MODEL_CARD_CARDSTACKSHOWCASE_H_ */
