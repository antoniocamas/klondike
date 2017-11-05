/*
 * CardStackRepresenterConsoleLinux.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#include "CardViewConsoleLinux.h"
#include "CardStackViewConsoleLinux.h"
#include "LinuxTerminalColor.h"

namespace card {

string CardStackViewConsoleLinux::representCard(Card card) {
	if (!card.isUpTurned())
		return "";

	CardViewConsoleLinux cardview(card);
	return cardview.getRepresentation(card);
}

CardStackViewConsoleLinux& CardStackViewConsoleLinux::operator =(CardStackView other) {
	CardStackView::operator =(other);
	return *this;
}

} /* namespace card */
