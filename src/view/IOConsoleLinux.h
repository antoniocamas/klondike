/*
 * IOConsoleLinux.h
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#ifndef SRC_UICONSOLELINUX_H_
#define SRC_UICONSOLELINUX_H_

#include "LinuxTerminalColor.h"
#include <vector>
#include <string>
#include <map>

using namespace std;

class IOConsoleLinux {
private:
	map<string, string> tableElementRepresenter;
public:
	IOConsoleLinux(std::map<string, string>& r);
	virtual ~IOConsoleLinux(){};

	void printHeader();
	void printRemainder(bool cardLeft);
	void printWaste(vector<string> cardsRepresentation);
	void printFoundation(vector<string> cardsRepresentation, int foundationNumber);
	void printPile(vector<string> cardsRepresentation, int pileNumber);
	void printMessage(string message);
	void printSplitter();
	void printNewLine();

	string getInput();

private:
	string getBasicRepresentation(string element){return this->getBasicRepresentation(element, 0);};
	string getBasicRepresentation(string element, int number);

};

void clear_screen();
#endif /* SRC_UICONSOLELINUX_H_ */
