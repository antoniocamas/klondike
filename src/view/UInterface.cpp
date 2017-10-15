/*
 * UInterface.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include <iostream>
#include <string>
#include "UInterface.h"
#include "../CardStackRepresenter.h"
#include "../CardStackRepresenterConsoleLinux.h"

using namespace std;

UInterface::~UInterface() {
	// TODO Auto-generated destructor stub
}

void UInterface::showTableau(Tableau& tableau) {
	//card::CardStackRepresenter cardRepresenter;
	card::CardStackRepresenterConsoleLinux cardRepresenter;

	cout << "\t" << "Remainder: ";

	io.printHeader();
	cardRepresenter = tableau.getRemainderRepresenter();
	io.printRemainder(cardRepresenter.getNumberOfCardsInTheStack() > 0);
	cardRepresenter = tableau.getWasterRepresenter();
	io.printWaste(cardRepresenter.topCard2String(3));

	for (int i = 0; i < tableau.getNumberOfFundations(); ++i){
		cardRepresenter = tableau.getFoundationRepresenter(i);
		io.printFoundation(cardRepresenter.topCard2String(), i);
	}

	io.printNewLine();
	io.printSplitter();

	for (int i = 0; i < tableau.getNumberOfPiles(); ++i){
			cardRepresenter = tableau.getPileRepresenter(i);
			io.printPile(cardRepresenter.allCard2String(), i);
	}
}
