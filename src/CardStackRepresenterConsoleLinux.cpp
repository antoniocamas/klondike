/*
 * CardStackRepresenterConsoleLinux.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#include "CardStackRepresenter.h"
#include "CardStackRepresenterConsoleLinux.h"

#include "Suit.h"
#include "LinuxTerminalColor.h"

namespace card {

CardStackRepresenterConsoleLinux::CardStackRepresenterConsoleLinux() {
	// TODO Auto-generated constructor stub

}

string CardStackRepresenterConsoleLinux::representCard(Card card) const {
	if (!card.isUpTurned())
		return "";

	string newCardRepresentation;
	const Suit suit = card.getSuit();
	if (suit.getName()=="Clubs")
		newCardRepresentation = BLACK + suit.getNickName(card.getNumber()) +string("C") + RESET;
	else if (suit.getName()=="Hearts")
		newCardRepresentation = RED + suit.getNickName(card.getNumber()) + string("H") + RESET;
	else if (suit.getName()=="Diamonds")
		newCardRepresentation = RED + suit.getNickName(card.getNumber()) + string("D") + RESET;
	else if (suit.getName()=="Spades")
		newCardRepresentation = BLACK + suit.getNickName(card.getNumber()) +string("S") + RESET;

	return newCardRepresentation;
}

CardStackRepresenterConsoleLinux::~CardStackRepresenterConsoleLinux() {
	// TODO Auto-generated destructor stub
}

CardStackRepresenterConsoleLinux& CardStackRepresenterConsoleLinux::operator =(
		CardStackRepresenter other) {
	CardStackRepresenter::operator =(other);
	return *this;
}

} /* namespace card */
