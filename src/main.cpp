/*
 * main.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include <iostream>
#include <vector>
#include "Klondike.h"

using namespace std;

int main ()
{
	cout << "Clondike Project" << endl;
	vector<int> test = {1,2};

	klondike::Klondike game;
	game.startGame();

	return 0;
}


