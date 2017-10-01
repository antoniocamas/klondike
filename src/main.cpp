/*
 * main.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include <iostream>
#include "Klondike.h"

using namespace std;

int main ()
{
	cout << "Clondike Project" << endl;

	klondike::Klondike game;
	game.startGame();

	return 0;
}


