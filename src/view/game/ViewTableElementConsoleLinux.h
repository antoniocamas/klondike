#ifndef SRC_VIEWTABLEELEMENTCONSOLELINUX_H_
#define SRC_VIEWTABLEELEMENTCONSOLELINUX_H_

#include <vector>
#include <string>
#include <map>
#include "LinuxTerminalColor.h"
#include "IOConsoleLinux.h"

using namespace std;

class ViewTableElementConsoleLinux: public IOConsoleLinux {
private:
    map<string, string> tableElementRepresenter;
public:
    ViewTableElementConsoleLinux(map<string, string>& r);
    virtual ~ViewTableElementConsoleLinux(){};

    void printHeader();
    void printMenuMessage();
    void printRemainder(bool cardLeft);
    void printWaste(vector<string> cardsRepresentation);
    void printFoundation(vector<string> cardsRepresentation, int foundationNumber);
    void printPile(vector<string> cardsRepresentation, int pileNumber);

private:
    string getBasicRepresentation(string element){return this->getBasicRepresentation(element, 0);};
    string getBasicRepresentation(string element, int number);
};

#endif /* SRC_VIEWTABLEELEMENTCONSOLELINUX_H_ */
