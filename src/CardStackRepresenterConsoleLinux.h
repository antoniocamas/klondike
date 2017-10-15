/*
 * CardStackRepresenterConsoleLinux.h
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#ifndef SRC_CARDSTACKREPRESENTERCONSOLELINUX_H_
#define SRC_CARDSTACKREPRESENTERCONSOLELINUX_H_

#include "CardStackRepresenter.h"
#include <string>

namespace card {

class CardStackRepresenterConsoleLinux: public CardStackRepresenter {
private:
	string representCard(Card card) const;

public:
	CardStackRepresenterConsoleLinux();
	virtual ~CardStackRepresenterConsoleLinux();

	CardStackRepresenterConsoleLinux & operator=(CardStackRepresenter other);
};

} /* namespace card */

#endif /* SRC_CARDSTACKREPRESENTERCONSOLELINUX_H_ */
