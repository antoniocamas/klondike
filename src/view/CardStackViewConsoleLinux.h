/*
 * CardStackRepresenterConsoleLinux.h
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#ifndef SRC_VIEW_CARDSTACKVIEWCONSOLELINUX_H_
#define SRC_VIEW_CARDSTACKVIEWCONSOLELINUX_H_

#include "CardStackView.h"

namespace card {

class CardStackViewConsoleLinux: public CardStackView {
public:
	CardStackViewConsoleLinux(){};
	virtual ~CardStackViewConsoleLinux(){};

	CardStackViewConsoleLinux & operator=(CardStackView other);

private:
	string representCard(Card card);
};

} /* namespace card */

#endif /* SRC_VIEW_CARDSTACKVIEWCONSOLELINUX_H_ */
