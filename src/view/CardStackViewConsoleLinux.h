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

class CardStackRepresenterConsoleLinux: public CardStackView {
private:
	std::map<string,vector<string>> suitFrenchDeckConsoleLinux;

public:
	//CardStackRepresenterConsoleLinux(map<string,vector<string>> * m): suitFrenchDeckConsoleLinux(m){};
	CardStackRepresenterConsoleLinux();
	virtual ~CardStackRepresenterConsoleLinux(){};

	CardStackRepresenterConsoleLinux & operator=(CardStackView other);

private:
	string representCard(Card card);
};

} /* namespace card */

#endif /* SRC_VIEW_CARDSTACKVIEWCONSOLELINUX_H_ */
