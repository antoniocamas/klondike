/*
 * MovementDescriber.h
 *
 *  Created on: Nov 9, 2017
 *      Author: antonio
 */

#ifndef SRC_MODEL_MOVEMENTDESCRIBER_H_
#define SRC_MODEL_MOVEMENTDESCRIBER_H_

#include <string>
#include "Card.h"

typedef enum {
	ORIGIN,
	DESTINATION,
	ORIGINCARD,
	NONE
}NextMovementElement;

typedef enum {
	REMAINDER2WASTE,
	WASTE2PILE,
	WASTE2FOUNDATION,
	FOUNDATION2PILE,
	PILE22FOUNDATION,
	PILE2PILE,
	NOTSUPPORTED
}MovementType;


using namespace std;
using namespace card;

class MovementDescriber {
private:
	string origin;
	unsigned int originIndex;
	string destination;
	unsigned int destinatioIndex;
	Card originCard;
	NextMovementElement nextElement;

public:
	MovementDescriber():originIndex(0), destinatioIndex(0), nextElement(ORIGIN){};
	virtual ~MovementDescriber(){};
	MovementType getType() const;
	NextMovementElement getNextExpectedElement() const{return nextElement;};

	unsigned int getOriginIndex()const {return originIndex;};
	unsigned int getDestinationIndex()const {return destinatioIndex;};
	Card getOriginCard()const {return originCard;};
	void setOrigin(string, int);
	void setDestination(string, int);
	void setOriginCard(Card);

private:
	void transition2NextMovementElement();
};

#endif /* SRC_MODEL_MOVEMENTDESCRIBER_H_ */
