/*
 * UInterface.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include <iostream>
#include <string>
#include "UInterface.h"
#include "LinuxTerminalColor.h"

using namespace std;

namespace klondike {

UInterface::~UInterface() {
	// TODO Auto-generated destructor stub
}

void UInterface::printTableLayout(void)
{

	cout << string(50, '\n');
	cout << RED << "Pile(" << this->table.getPileSize() <<") [p]\n" << RESET;
}

} /* namespace klondike */
