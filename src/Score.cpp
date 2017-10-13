/*
 * Score.cpp
 *
 *  Created on: Oct 13, 2017
 *      Author: antonio
 */

#include <cmath>
#include "Score.h"

Score::~Score() {
	// TODO Auto-generated destructor stub
}

void Score::addPoints(int newPoints) {
	if (newPoints < 0 and std::abs(newPoints) > this->points) {
		this->points = 0;
	}
	else {
		this->points += newPoints;
	}

}
