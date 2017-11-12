#ifndef UINTERFACE_H_
#define UINTERFACE_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "View.h"
#include "IOConsoleLinux.h"
#include "Card.h"

using namespace std;

class ViewConsoleLinux: public View {

private:
	map<string,string> tableElementRepresenter = {
			{"remainder", "r"}, {"waste", "w"}, {"foundation","f"},
			{"pile", "p"}, {"backCard", "@"}, {"card", ".{1,2}[aA-zZ]"}
	};

	IOConsoleLinux io;

public:
	ViewConsoleLinux(): io(this->tableElementRepresenter){};
	virtual ~ViewConsoleLinux(){};
	void showTable();
	void showWinMessage();
	MovementDescriber getNextMovement();
private:
	static void inline printMessage(const string message) { cout << message << endl; }
	vector<string> cards2String(vector<const card::Card*>);
};

#endif /* UINTERFACE_H_ */
