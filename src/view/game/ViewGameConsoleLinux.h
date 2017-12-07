#ifndef VIEWGAMECONSOLELINUX_H_
#define VIEWGAMECONSOLELINUX_H_

#include <vector>
#include <string>
#include <memory>

#include "IOConsoleLinux.h"
#include "Table.h"
#include "Card.h"
#include "MovementDescriber.h"
#include "ViewTableElementConsoleLinux.h"

using namespace std;

class ViewGameConsoleLinux {

private:
    Table * table;
    map<string,string> tableElementRepresenter = {
	{"remainder", "r"}, {"waste", "w"}, {"foundation","f"},
	{"pile", "p"}, {"backCard", "@"}, {"card", ".{1,2}[aA-zZ]"},
	{ "menu", "m"}
    };

    ViewTableElementConsoleLinux io;

public:
    ViewGameConsoleLinux(Table *t): table(t), io(this->tableElementRepresenter){};
    virtual ~ViewGameConsoleLinux(){};
    void showTable();
    void showWinMessage();
    MovementDescriber getNextMovement();
private:
    static void printMessage(const string message);
    vector<string> cards2String(vector<const card::Card*>);
};

#endif /* VIEWGAMECONSOLELINUX_H_ */
