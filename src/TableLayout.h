/*
 * TableLayout.h
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#ifndef TABLELAYOUT_H_
#define TABLELAYOUT_H_

#include <array>
#include <vector>

using namespace std;

namespace klondike {

class TableLayout {
private:

	vector<int> pile;
	vector<int> visible_pile;
	array<vector<int>, 4> suit_piles;
	array<vector<int>, 8> stacks;


public:
	TableLayout();
	void Deal();
	int getPileSize(){return pile.size();}
	virtual ~TableLayout();
};

} /* namespace klondike */

#endif /* TABLELAYOUT_H_ */
