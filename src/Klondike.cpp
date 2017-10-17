/*
 * Klondike.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include "Klondike.h"
#include "Tableau.h"
#include "view/UInterface.h"

Klondike::~Klondike() {
	// TODO Auto-generated destructor stub
}

void Klondike::startGame()
{
	UInterface uinterface;

	uinterface.showTableau(this->tableau);


}
