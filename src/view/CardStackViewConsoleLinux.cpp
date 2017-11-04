/*
 * CardStackRepresenterConsoleLinux.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#include "CardStackViewConsoleLinux.h"

#include <map>
#include <vector>
#include <string>
#include "Suit.h"
#include "CardStackView.h"
#include "LinuxTerminalColor.h"

namespace card {

CardStackRepresenterConsoleLinux::CardStackRepresenterConsoleLinux() {
	this->suitFrenchDeckConsoleLinux = {
			{"Clubs", {BLACK,string("C")}}, {"Hearts", {RED, string("H")}},
			{"Spades", {BLACK, string("S")}}, { "Diamonds", {RED, string("D")}}
	};
}

string CardStackRepresenterConsoleLinux::representCard(Card card) {
	if (!card.isUpTurned())
		return "";


	return suitFrenchDeckConsoleLinux[card.getSuit().getName()].at(0) +
			card.getSuit().getNickName(card.getNumber()) +
			suitFrenchDeckConsoleLinux[card.getSuit().getName()].at(1) + RESET;
}

CardStackRepresenterConsoleLinux& CardStackRepresenterConsoleLinux::operator =(
		CardStackView other) {
	CardStackView::operator =(other);
	return *this;
}

} /* namespace card */
